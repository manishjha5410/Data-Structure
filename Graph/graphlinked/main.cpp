#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int>g[],vector<int>&v,int x)
{
    cout<<x<<" ";
    v[x]=1;
    int c;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        c=q.front();
        q.pop();
        for(int i=0;i<g[c].size();i++)
            if(v[g[c][i]]==0)
            {
                cout<<g[c][i]<<" ";
                v[g[c][i]]=1;
                q.push(g[c][i]);
            }
    }

    for(int i=0;i<v.size();i++)
        if(v[i]==0)
            bfs(g,v,i);
}


int dfsutil(vector<int>g[],vector<int>&v,int x)
{
    if(v[x]==0)
    {
        cout<<x<<" ";
        v[x]=1;
        for(int i=0;i<g[x].size();i++)
            dfsutil(g,v,g[x][i]);
    }
}
/*
4 6
0 2
2 0
0 1
1 2
2 3
3 3
2

5 6
0 2
2 0
4 4
1 2
2 3
3 3
2
*/
int dfs(vector<int>g[],vector<int>v,int x)
{
    dfsutil(g,v,x);
    for(int i=0;i<v.size();i++)
        if(v[i]==0)
            dfsutil(g,v,i);
}

int dfsit(vector<int>g[],vector<int>&v,int x)
{
    cout<<x<<" ";
    stack<int>s;
    v[x]=1;
    int c;
    s.push(x);
    while(!s.empty())
    {
        c=s.top();
        s.pop();
        for(int i=0;i<g[c].size();i++)
            if(v[g[c][i]]==0)
            {
                cout<<g[c][i]<<" ";
                v[g[c][i]]=1;
                s.push(g[c][i]);
            }
    }
    for(int i=0;i<v.size();i++)
        if(v[i]==0)
            dfsit(g,v,i);
}

int topologicalsortutil(vector<int>g[],vector<int>&v,int x,stack<int>&s)
{
    v[x]=1;
    for(int i=0;i<g[x].size();i++)
        if(v[x]==0)
            topologicalsortutil(g,v,i,s);
    s.push(x);
}

int topologicalsort(vector<int>g[],vector<int>&v)
{
    stack<int>s;
    for(int i=0;i<v.size();i++)
        topologicalsortutil(g,v,i,s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int topologicalsortit(vector<int>g[],int n)
{
    queue<int>q;
    int x,c=0;
    vector<int>in_degree(n,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<g[i].size();j++)
            in_degree[g[i][j]]++;
    for(int i=0;i<in_degree.size();i++)
        if(in_degree[i]==0)
            q.push(i);
    vector<int>value;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        value.push_back(x);
        for(auto i=g[x].begin();i!=g[x].end();i++)
                if(--in_degree[*i]==0)
                    q.push(*i);
        c++;
    }
    if(c!=n)
        cout<<"Graph is cyclic"<<endl;
    else
        for(int i=0;i<value.size();i++)
            cout<<value[i]<<" ";
}

bool isCyclic(vector<int>g[],vector<int>&v,int x)
{
    queue<int>q;
    q.push(x);
    v[x]=1;
    int c;
    while(!q.empty())
    {
        c=q.front();
        q.pop();
        v[c]=1;
        for(int w=0;w<g[c].size();w++)
            if(v[g[c][w]]==1)
                return true;
            else
            {
                v[g[c][w]]==1;
                q.push(g[c][w]);
            }
    }

    for(int i=0;i<v.size();i++)
        if(v[i]==0)
            isCyclic(g,v,i);
    return false;
}

/*
6 6
5 0
5 2
4 0
4 1
2 3
3 1

5 5
0 1
1 2
2 3
3 4
4 2

*/

int main()
{
	int n,a,e,b,x;
    cin>>n>>e;
    vector<int>g[n];
    vector<int>in_g[n];
     auto start = chrono::high_resolution_clock::now();
    vector<int>v(n,0);
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }

    if(isCyclic(g,v,0))
        cout<<"Graph is cyclic";
    else
        cout<<"Graph is acyclic";
    auto finish = chrono::high_resolution_clock::now();
    cout<<endl <<"Time taken in nano secondes " <<chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
	return 0;
}
