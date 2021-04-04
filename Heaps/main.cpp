#include <bits/stdc++.h>
using namespace std;

int Insert(int a[],int n)
{
    int temp,i=n;
    temp=a[n];
    while(i>1 && temp>a[i/2]) // for min heap write temp<a[i/2] in place of temp>a[i/2]
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int create(int a[],int n)
{
    for(int i=0;i<n;i++)
        Insert(a,i);
}

void display(int *a,int n)
{
    for(auto i=1;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int Delete(int *a,int n)
{
    int x,i,j;
    x=a[1];
    a[1]=a[n-1];
    i=1;j=2*i;
    while(j<n-1)
    {
        if(a[j+1]>a[j])
            j=j+1;
        if(a[j]>a[i])
        {
            swap(a[i],a[j]);
            i=j;
            j=2*j;
        }
        else
            break;
    }
    a[n-1]=x;
}

void heapify(int *a,int n,int i)
{
    int largest = i;
	int j = 2*i;

	if(j<n && a[j]>a[largest])
		largest=j;

	if(j+1<n && a[j+1]>a[largest])
		largest=j+1;

	if(largest!=i)
    {
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}

void buildHeap(int *a,int n)
{
	int startIdx=(n/2)-1;
	for(int i=startIdx;i>0;i--)
		heapify(a,n,i);
}


int main()
{
    int a[]={0,10,40,20,30,25,5,35};
    int b[]={0,10,40,20,30,25,5,35};
    int len = sizeof(a)/sizeof(a[0]);
    create(a,len);
    display(a,len);
    buildHeap(b,len);
    display(b,len);
//    for(int i=len;i>1;i--)
//        Delete(a,i);
//    display(a,len);
}
