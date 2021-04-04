#include<stdio.h>

int q[20],top=-1,front=-1,rear=-1,a[20][20],v[20],s[20];
int delete();
void add(int item);
int bfs(int s,int n);
int dfs(int s,int n);
void push(int item);
int pop();

int main()
{
    int n,i,s,ch,j;
    int c=1;
    printf("Here Nodes are starting from 1 onwards \n");
    printf("Enter Number of vertices : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("Enter 1 if %d has a node with %d else 0 : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The adjacency matrix is \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    while(c==1)
    {
        for(i=1;i<=n;i++)
        v[i]=0;
        err: printf("Menu\n");
        printf("1.B.F.S\n");
        printf("2.D.F.S\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        printf("\nEnter source vertex : ");
        scanf("%d",&s);

        switch(ch)
        {
            case 1:
                printf("B.F.S. from vertex %d \n",s);
                bfs(s,n);
            break;
            case 2:
                printf("D.F.S. from vertex %d \n",s);
                dfs(s,n);
            break;
            default:
                printf("Wrong choice enter one again\n");
                goto err;
        }
        printf("\nEnter 1 to continue else for exit \n");
        scanf("%d",&c);
    }
}


int bfs(int s,int n)
{
    int b=0,c=0,r=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                c=1;
                break;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                r=1;
                break;
            }
        }
        if(c==0 && r==0)
        {
            printf("B.F.S. not possible \n");
            return 0;
        }
    }
    int p,i;
    add(s);
    v[s]=1;
    p=delete();
    if(p!=0)
        printf("%d ",p);
    while(p!=0)
    {
        for(i=1;i<=n;i++)
            if((a[p][i]!=0)&&(v[i]==0))
            {
                add(i);
                v[i]=1;
            }
        p=delete();
        if(p!=0)
            printf("%d ",p);
    }
    for(i=1;i<=n;i++)
        if(v[i]==0)
            bfs(i,n);
    return;
}


void add(int item)
{
    if(rear==19)
        printf("QUEUE FULL");
    else
    {
        if(rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else
            q[++rear]=item;
    }
}

int delete()
{
    int k;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        k=q[front++];
        return(k);
    }
}


int dfs(int s,int n)
{
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
                c=1;
        }
        if(c==0)
            printf("D.F.S. not possible\n");
        return 0;
    }
    int i,k;
    push(s);
    v[s]=1;
    k=pop();
    if(k!=0)
        printf("%d ",k);
    while(k!=0)
    {
        for(i=1;i<=n;i++)
            if((a[k][i]!=0)&&(v[i]==0))
            {
                push(i);
                v[i]=1;
            }
        k=pop();
        if(k!=0)
            printf("%d ",k);
    }
    for(i=1;i<=n;i++)
        if(v[i]==0)
            dfs(i,n);
    return;
}

void push(int item)
{
    if(top==19)
        printf("s overflow ");
    else
        s[++top]=item;
}

int pop()
{
    int k;
        if(top==-1)
    return(0);
    else
    {
        k=s[top--];
        return(k);
    }
}
