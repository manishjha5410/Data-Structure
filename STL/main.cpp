#include <bits/stdc++.h>
using namespace std;

int Pair()
{
    pair <int,bool> p,q;
    p= make_pair(7,true);
    q= make_pair(8,false);
    cout<<p.first<<" "<<p.second<<endl;
    cout<<q.first<<" "<<q.second<<endl;
    swap(p,q);
    cout<<p.first<<" "<<p.second<<endl;
    cout<<q.first<<" "<<q.second<<endl;

    return 0;
}

void showlist(list <int> l)
{
    list <int>::iterator it;
    for(it=l.begin();it!=l.end();++it)
        cout<<*it<<" ";
    cout<<endl;
}

int multipleoffive(int value)
{
    if(value%5==0)
        return true;
    return false;
}

void List()
{
    list <int> l,p;
    list <int>::iterator it=l.end();
    for(int i=0;i<10;i++)
        l.push_back(i*2);
    showlist(l);
    cout<<l.front()<<" "<<l.back()<<" "<<l.empty()<<endl;
    l.pop_front();
    l.pop_back();
    showlist(l);
    l.insert(it,5,100);
    showlist(l);
    l.remove(4); // remove(x) is x based on value if multiple exist removes all
    showlist(l);
    l.remove_if(multipleoffive);
    showlist(l);
    l.sort();
    showlist(l);
    p=l;
    showlist(p);
    l.merge(p);
    showlist(l);
    l.unique();
    showlist(l);
}

int Array()
{
    array<int,10> a,b;
    a={10,30,20,90,80,60,40,70,40,50};
    b={100,300,200,900,800,600,400,700,400,500};
    cout<<a.at(3)<<" "<<a[3]<<" "<<get<3>(a)<<endl;
    cout<<a.front()<<" "<<a.back()<<" "<<a.size()<<" "<<a.max_size()<<a.empty()<<endl;

    for(int i=0;i<a.size();i++)
        cout<<" "<<a[i];
    cout<<endl;
    for(int i=0;i<b.size();i++)
        cout<<" "<<b[i];
    cout<<endl;
    a.swap(b);
    for(int i=0;i<a.size();i++)
        cout<<" "<<a[i];
    cout<<endl;
    for(int i=0;i<b.size();i++)
        cout<<" "<<b[i];
        cout<<endl;

    a.fill(20);

    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";

    cout<<endl;
    return 0;
}

int Vector()
{
    vector <int> v = {5,4,3,2,1};
    v.reserve(5);
    cout<<v.front()<<" "<<v.back()<<endl;
    cout<<v.size()<<" "<<v.max_size()<<" "<<v.capacity()<<endl;
    v.push_back(7);
    vector <int> w;
    w.assign(5,20);
    w=v;
    int a[] = {1,2,3,4,5,6,7,8,9};
    w.assign(a+3,a+9);
    for(int i=0;i<w.size();i++)
        cout<<" "<<w[i];
    cout<<endl;
    int *p = v.data();
    for(int i=0;i<v.size();i++)
        cout<<" "<<*(p++);
        cout<<endl;
    w.erase(w.begin());
    for(int i=0;i<w.size();i++)
        cout<<" "<<w[i];
    return 0;
}

class Person
{
    public:
        float age;
        string name;
    bool operator < (const Person& rhs) const { return name<rhs.name; }
    bool operator > (const Person& rhs) const { return name>rhs.name; }

};

int Set()
{
    set <int>::iterator it;
    set <int> a;
    set <int>::key_compare comp = a.key_comp();
    set <int>::value_compare comp1 = a.key_comp();
    a = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,8,9};
    set<Person,greater<>> s={{20,"Manish"},{40,"Kite"},{50,"Mike"}};

    a.insert(12);

    cout<<a.size()<<" "<<a.max_size()<<endl;

    a.erase(12);

    for(int i:a)
        cout<<i<<" ";
    cout<<endl;
        cout<<*a.lower_bound(3)<<" "<<*a.upper_bound(3)<<endl;
    cout<<*a.crbegin()<<" "<<comp(*a.begin(),*a.rbegin())<<endl;
    cout<<*a.crbegin()<<" "<<comp1(*a.rbegin(),*a.begin())<<endl; // comp means compare
    cout<<*(a.equal_range(2)).first<<" "<<*(a.equal_range(2)).second;
    int *p;
    cout<<endl<<sizeof(p);

    for(int i:a)
        cout<<i<<" ";

    cout<<"\n";
    for(int n:{1,2,3,4,5,6,7,8,9})
        cout<<n<<" ";
    cout<<"\n";
    string s1 = "Hello I am Manish";
    for(auto c: s1)
        cout<<c<<" ";
    cout<<"\n";

     for(const auto& e:s)
        cout<<e.age<<" "<<e.name<<" "<<endl;

    for(auto e:s)
        cout<<e.age<<" "<<e.name<<" "<<endl;


    cout<<endl;
    return 0;
}

int MultiSet()
{
    multiset<int> a= {7,8,7,2,2,3,4,5};
    multiset<string> b={"TitforTat"};
    auto itr = a.insert(a.begin(),1);
    a.insert(6);
    a.insert(0);
    itr = a.insert(itr,8);
    for(auto i:a)
        cout<<i<<" ";
        cout<<endl;
    cout<<*a.begin()<<" "<<*a.end()<<" "<<a.size()<<" "<<a.max_size()<<" "<<a.empty()<<endl;
    cout<<*a.upper_bound(3)<<" "<<*a.lower_bound(3)<<endl;
    cout<<*a.upper_bound(7)<<" "<<*a.lower_bound(7)<<endl;
    auto pos = a.find(3);
    for(auto it = pos;it!=a.end();it++)
        cout<<*it<<" ";
    cout<<"\n";

    for(auto i:b)
        cout<<i<<" ";
        cout<<endl;

    return 0;
}

int product(int x,int y)
{
    return x * y;
}

int Numeric_Header()
{
    int a[] = {1,2,3,4,5,6,7,8,9,0},var = 5;
    int b[10];

    int c[] = {1,2,3};
    int d[] = {2,3};
    adjacent_difference(a,a+10,b);

    adjacent_difference(a,a+10,b,product);

    adjacent_difference(a,a+10,b,multiplies<int>());

    cout<<addressof(a[0])<<" "<<&a[0];

    for(auto i:b)
        cout<<i<<" ";
    cout<<"\n";
    cout<<inner_product(c,c+3,d,var)<<endl; // c=[c1,c2,c3] d=[d1,d2,d3] res=c1*v1+c2*v2+c3*v3+var
    iota(c,c+3,20);
    for(auto i:c)
        cout<<i<<" ";
    return 0;
}

int Map()
{
    map<string,vector<int>,greater<>>m;
    m["Bholu"].push_back(12345);
    m["Bholu"].push_back(21872);
    m["Abhi"].push_back(98654);
    m["Abhi"].push_back(54231);
    m["Abhi"].push_back(90826);
    //m.insert(make_pair("Chil",{65432}));
    for(auto i:m)
    {
        cout<<i.first<<" ";
        for(auto k:i.second)
            cout<<k<<" ";
        cout<<"\n";
    }
    //cout<<m["Chil"]<<endl;

    map<int,int>a;
    a.insert(pair<int,int>(1,2));
    a.insert(pair<int,int>(2,7));
    a.insert(pair<int,int>(3,0));
    a.insert(pair<int,int>(4,6));
    a.insert(pair<int,int>(5,9));
    a.insert(pair<int,int>(6,2));

    for(auto i=a.begin();i!=a.end();i++)
        cout<<i->first<<" "<<i->second<<" "<<endl;
    cout<<endl;
    for(auto kv:a)
        cout<<kv.first<<" "<<kv.second<<endl;
    cout<<endl;
    map<int,int> b(a.begin(),a.find(3));
    map<int,int> c(a.begin(),a.end());
    c.erase(c.begin(),c.find(5));
    for(auto kv:c)
        cout<<kv.first<<" "<<kv.second<<endl;
    cout<<endl;
    cout<<a.at(4)<<endl;
    cout<<a.erase(2)<<endl; //returns boolean
    cout<<a.count(3)<<endl; //present return 1 else return 0
    pair<map<int,int>::iterator,map<int,int>::iterator>itp;
    itp=a.equal_range(1);
    cout<<"lower bound of ( 1 ) "<<a.equal_range(1).first->first<<" "<<a.equal_range(1).first->second<<endl;
    cout<<"upper bound of ( 1 ) "<<itp.second->first<<" "<<itp.second->second<<endl;

    for(auto op:a)
        cout<<op.first<<" "<<op.second<<endl;
    auto iterator = a.rend();
    iterator--;
    cout<<iterator->first<<" "<<iterator->second;
    return 0;
}

int Valarry()
{
    valarray<int> a={1,2,3,4,5,6,2};
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";
    cout<<a[2]<<" "<<a.max()<<" "<<a.min()<<" "<<a.sum()<<" "<<endl;
    a=a.apply([](int x){return x*=5;});
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";
    a=a.cshift(2);
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
    /*
        valarray size() function in C++
        valarray swap() function in c++
        valarray resize() function in C++
        valarray begin() function in C++
        valarray end() function in C++
        valarray abs() function in C++
        valarray log10() function in C++
        valarray sin() function in C++
        valarray exp() function in C++
        valarray sinh() function in C++
        valarray acos() function in C++
        valarray cos() function in C++
        valarray tan() function in C++
        valarray atan() function in C++
        valarray pow() function in C++
        valarray log() function in C++
        valarray cosh() function in C++
        valarray sqrt() function in C++
        valarray tanh() function in C++
     */ // all have same like a=exp(a)
}

int Multimap()
{
    multimap<char,int> a;
    a.insert(pair<char,int>('a',1));
    a.insert(pair<char,int>('a',2));
    a.insert(make_pair('a',3));
    a.insert(pair<char,int>('b',1));
    a.insert(pair<char,int>('b',2));
    a.insert(pair<char,int>('b',1));
    a.insert(pair<char,int>('c',5));
    pair<multimap<char,int>::iterator,multimap<char,int>::iterator> p = a.equal_range('b');
    for(auto& i:a)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;
    for(auto ip=p.first;ip!=p.second;ip++)
        cout<<ip->first<<" "<<ip->second<<endl;
    cout<<endl;
    auto r = a.lower_bound('b');
    cout<<r->first<<" "<<r->second<<endl;
    r = a.upper_bound('b');
    cout<<r->first<<" "<<r->second<<endl;
    cout<<endl<<a.erase('c'); // gives number of key with value 'a'
    cout<<endl;
    cout<<a.count('a');
    cout<<endl;
    for(auto& i:a)
        cout<<i.first<<" "<<i.second<<endl;
    auto it = a.begin();
    auto comp = a.key_comp();
    do
    {
        cout<<it->first<<" "<<it->second<<endl;
    }while(comp((*it++).first,a.rbegin()->first));
    return 0;
}

class A
{
    public: int x;
    A(int x=0): x{x} { cout<<"Construct"<<endl; };
    A(const A& rhs) { x=rhs.x;cout<<"Copy"<<endl; }
};

bool operator < (const A& lhs,const A& rhs) { return lhs.x<rhs.x; }

int Emplace()
{
    set<A> o;
    A a(10);
   // o.insert(a);
    o.emplace(12);
    o.emplace_hint(o.begin(),2);
    o.emplace_hint(o.begin(),2);
    for(auto& l:o)
        cout<<l.x<<endl;
}

int unorderedSet()
{
    unordered_set<int>u;
    u.reserve(3);
    u={1,5,3,2,4,6,1};
    for(auto& z:u)
        cout<<z<<" ";
    cout<<endl;
    auto search = u.find(5);
    u.insert(8);
    u.insert(10);
    u.insert(40);
    u.insert(50);
    u.insert(80);
    u.insert(70);
    if(search!=u.end())
        cout<<"Found "<<(*search)<<'\n';
    else
        cout<<"Not found "<<'\n';
    unordered_set<int>::iterator itr;
    for(itr=u.begin();itr!=u.end();itr++)
        cout<<*itr<<" ";
    cout<<endl;
    cout<<endl;
    cout<<u.bucket_size(3)<<" "<<u.bucket_count()<<endl;
    unordered_set<int>::hasher fn = u.hash_function(); // load_factor = size / bucket_count
    cout<<fn(5)<<endl;
    cout<<u.load_factor()<<" "<<u.max_load_factor()<<endl;
    auto up = u.begin();
    up=up++;up=up++;up=up++;
    u.emplace_hint(up,120);
    for(itr=u.begin();itr!=u.end();itr++)
        cout<<*itr<<" ";
}

int unorderedMultiset()
{
    unordered_multiset<int>a={1,5,3,5,2,3,3,6};
    auto search = a.find(3);
    for(auto& i:a)
        cout<<i<<" ";
    cout<<endl;
    cout<<*search<<" ";
    if(a.empty())
        cout<<"Empty";
    else
        cout<<"NOT Empty";
    cout<<endl;
    cout<<a.count(5)<<endl;
    a.erase(search);
    for(auto& i:a)
        cout<<i<<" ";
    cout<<endl;
}

int unOrderedMap()
{
    unordered_map<int,int>a={{6,32},{12,212}};
    a.insert(make_pair<int,int>(1,56));
    a.insert(make_pair<int,int>(2,454));
    a.insert(make_pair<int,int>(3,44));
    a.insert(make_pair<int,int>(4,446));
    for(auto i:a)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;
    a[4]=900;
    for(auto i:a)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;
    a[10]++;
    for(auto i:a)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;
}

int Deque()
{
    deque<int>a;
    {
        a.push_front(5);
        a.push_back(6);
        a.push_front(7);
        a.push_back(9);
        for(auto i:a)
            cout<<i<<" ";
        cout<<endl;
    }
    {
        a.pop_back();
        a.pop_front();
        a.emplace_front(12);
        a.emplace_back(13);
        for(auto i:a)
            cout<<i<<" ";
    }
}

int PriorityQueue()
{
    {
        priority_queue<int>a;
        for(auto e: {2,7,3,1,4,9,0,3})
            a.push(e);
        while(!a.empty())
        {
            cout<<a.top()<<" ";
            a.pop();
        }
        cout<<endl;
    }
    {
        priority_queue<int,vector<int>,greater<>>a;
        for(auto e: {2,7,3,1,4,9,0,3})
            a.push(e);
        while(!a.empty())
        {
            cout<<a.top()<<" ";
            a.pop();
        }
        cout<<endl;
    }
    {
        auto cmp=[](int left,int right){ return left>2*right; };
        priority_queue<int,vector<int>,decltype(cmp)> a(cmp);

        for(auto e: {2,7,3,1,4,9,0,3})
            a.push(e);

        while(!a.empty())
        {
            cout<<a.top()<<" ";
            a.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // faster coding
    cin.tie(NULL); // faster coding
    PriorityQueue();
    return 0;
}
