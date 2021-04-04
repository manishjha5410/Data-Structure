#include <bits/stdc++.h>

using namespace std;

class comparer
{
    public:
    int operator() (const pair<int,pair<int,int>>& p1, const pair<int,pair<int,int>>& p2)
    {
        return p1.first > p2.first;
    }
};

int getMin(map<int,int>&m)
{
    multimap<int,int>kr;

    for(auto x:m)
        kr.insert(make_pair(x.second,x.first));

    for(auto x:kr)
        return x.second;
}

bool find(map<int,int>m,int x)
{
    auto c = m.find(x);
    if(c!=m.end())
        return true;
    return false;
}


int prism(vector<vector<pair<int,int>>>g)
{
    vector<int>p(g.size(),-1);
    vector<vector<pair<int,int>>>pr(g.size(), vector<pair<int,int>>());
    map<int,int>k;
    k[0]=0;
    for(int i=1;i<g.size();i++)
        k[i]=INT_MAX;
    int c,x;
    while(k.size()!=0)
    {
        c = getMin(k);
        x=k[c];
        k.erase(c);
        for (auto j=0; j<g[c].size(); ++j)
            if(find(k,g[c][j].first))
                if(k[g[c][j].first]>g[c][j].second)
                {
                    k[g[c][j].first]=g[c][j].second;
                    p[g[c][j].first]=c;
                }
    }

    for(int i=0;i<p.size();i++)
        cout<<i<<" "<<p[i]<<endl;
}

int findParent(vector<int>&v,int x)
{
    while(x>0)
        x=v[x];
    return x;
}

int unionElement(vector<int>&v,int a,int b)
{
    if(v[a]>=v[b])
    {
        cout<<a<<" "<<b<<" "<<endl;
        v[a]=0-(abs(v[a])+abs(v[b]));
        v[b]=a;
    }
    else
    {
        cout<<a<<" "<<b<<" "<<endl;
        v[b]=0-(abs(v[a])+abs(v[b]));
        v[a]=b;
    }
}

int kruskal(vector<vector<pair<int,int>>>g,int n)
{
    vector<int>p(n,-1);
    vector<pair<int,pair<int,int>>>kr(g.size(), pair<int,pair<int,int>>());

    priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, comparer > pq;

    for(auto i=0; i<g.size(); ++i)
    {
        for (auto j=0; j<g[i].size(); ++j)
            pq.push(make_pair(g[i][j].second,make_pair(i,g[i][j].first)));
    }


//    while(!pq.empty())
//    {
//        cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
//        pq.pop();
//    }

    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int p1 = findParent(p,x.second.first);
        int p2 = findParent(p,x.second.second);

        if(p1!=p2 || p1==-1 || p2==-1)
        {
            unionElement(p,x.second.first,x.second.first);
//cout<<x.second.first<<" "<<x.second.second<<endl;
        }
    }

    for(int i=0;i<n;i++)
        cout<<p[i]<<" ";
}

int main()
{
    int n,e,a,b,c;
    cin>>n>>e;
    vector<vector<pair<int,int>>>g(n, vector<pair<int,int>>());

    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
//        g[b].push_back(make_pair(a,c));
    }
    cout<<endl<<"-----------------------"<<endl;

//    for(auto i=0; i<g.size(); ++i)
//    {
//        for (auto j=0; j<g[i].size(); ++j)
//            cout<<i<<" "<<g[i][j].first<<" "<<g[i][j].second<<" "<<endl;
//    }
//
//    cout<<g.size();

    kruskal(g,n);
}

/*

9 13
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
4 5 10

5 7
0 1 10
0 2 20
1 2 30
3 2 15
1 3 5
3 4 8
2 4 6

*/
