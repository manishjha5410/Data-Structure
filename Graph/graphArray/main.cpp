#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100];
int a[100][100];

int bfs(int *v,int x)
{
    int i=0;
    queue<int>q;

        arr[i]=x+1;
        i++;
        int u;
        v[x]=1;
        q.push(x);
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(int j=0;j<n;j++)
                if(a[u][j]==1 && v[j]==0)
                {
                    arr[i]=j+1;
                    i++;
                    q.push(j);
                    v[j]=1;
                }
        }
        for(int i=0;i<n;i++)
            if(v[i]==0)
            {
                cout<<"BFS not possible as vertex "<<v[i]+1<<" can't be reached ";
                return 0;
            }
                for(int i=0;i<n;i++)
                    cout<<arr[i]<<" ";
}

int dfs(int *v,int x)
{
    if(v[x]==0)
    {
        cout<<x+1<<" ";
        v[x]=1;
        for(int i=0;i<n;i++)
            if(a[x][i]==1)
                dfs(v,i);
    }
}

int dfsit(int *v,int x)
{
    stack<int>s;
    int i=0;
    arr[i]=x+1;
    i++;
    v[x]=1;
    int u;
    s.push(x);
    while(!s.empty())
    {
        u=s.top();
        s.pop();
        for(int j=0;j<n;j++)
            if(a[u][j]==1 && v[j]==0)
            {
                arr[i]=j+1;
                v[j]=1;
                i++;
                s.push(j);
            }
    }
    for(int j=0;j<n;j++)
        if(v[j]==0)
        {
            cout<<"DFS not possible as vertex "<<j+1<<" can't be reached ";
            return -1;
        }
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
}

int topologicalsortit(int n)
{
    queue<int>q;
    int x,c=0;
    int in_degree[n];
    for(int i=0;i<n;i++)
        in_degree[i]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]==1)
                in_degree[j]++;
    for(int i=0;i<n;i++)
        if(in_degree[i]==0)
            q.push(i);
    int value[n];
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        value[c]=x;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==1 && --in_degree[j]==0)
                    q.push(j);
        c++;
    }
    if(c!=n)
        cout<<"Graph is cyclic"<<endl;
    else
        for(int i=0;i<n;i++)
            cout<<value[i]+1<<" ";
}

int main()
{
    cout<<"Here Nodes start from 1\n";
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter data\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int x;
    cout<<"Enter starting vertex : ";
    cin>>x;
    x--;

    int v[7];
    for(int i=0;i<n;i++)
        v[i]=0;
    topologicalsortit(n);
}
