#include <bits/stdc++.h>
using namespace std;

string evaluate(int a,int b,string x)
{
    if(x=="+")
        return to_string(a+b);
    else if(x=="-")
        return to_string(a-b);
    else if(x=="*")
        return to_string(a*b);
    else if(x=="%")
        return to_string(a%b);
    else if(x=="/")
        return to_string(a/b);
    else
        return to_string(a^b);
}

string evaluatePost(string x)
{
    stack<string> s;
    int a,b;
    x=" "+x+" ;";
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/' || x[i]=='%' || x[i]=='^')
        {
            a=stoi(s.top());
            s.pop();
            b=stoi(s.top());
            s.pop();
            s.push(evaluate(b,a,string(1,x[i])));
        }
        else if(x[i-1]!='+' && x[i-1]!='-' && x[i-1]!='*' && x[i-1]!='/' && x[i-1]!='%' && x[i-1]!='^' && !isdigit(x[i]))
        {
            int g=i;
            string q="";
            bool f = true;
            while((x[g]!=' ' || f) && g!=0)
            {
                q+=x[g];
                g=g-1;
                f=false;
            }
            if(q!="")
            {
                reverse(q.begin(),q.end());
                s.push(q);
            }
        }
    }
    s.pop();
    return s.top();
}


string evaluatePre(string x)
{
    stack<string> s;
    int a,b;
    x=x+" ;";
    reverse(x.begin(),x.end());
    for(int j=0;j<x.size();j++)
    {
        if(x[j]=='+' || x[j]=='-' || x[j]=='*' || x[j]=='/' || x[j]=='%' || x[j]=='^')
        {
              a=stoi(s.top());
              s.pop();
              b=stoi(s.top());
              s.pop();
              string v(1,x[j]);
              s.push(evaluate(a,b,v));
        }
        else if(x[j]==' ' && x[j-1]!='+' && x[j-1]!='-' && x[j-1]!='*' && x[j-1]!='/' && x[j-1]!='%' && x[j-1]!='^' && x[j]!=';')
        {
            int g=j;
            string q="";
            bool f = true;
            while((x[g]!=' ' || f) && g!=0)
            {
                q+=x[g];
                g=g-1;
                f=false;
            }
            reverse(q.begin(),q.end());
            s.push(q);
        }
    }
    return s.top();
}

int isbalanced(string x)
{
    stack<char> s;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='(' || x[i]=='[' || x[i]=='{' || x[i]==')' || x[i]==']' || x[i]=='}')
        {
            if(x[i]=='(' || x[i]=='[' || x[i]=='{')
                s.push(x[i]);
            else if(x[i]==')' && s.top()=='(')
                s.pop();
            else if(x[i]==']' && s.top()=='[')
                s.pop();
            else if(x[i]=='}' && s.top()=='{')
                s.pop();
            else
                return -1;
        }
    }
    return s.empty()==true?0:-1;
}

int prec(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/' || x=='%')
        return 2;
    else if(x=='^')
        return 3;
    return 0;
}
string infixToPostFix(string x)
{
    stack<string>s;
    string y="";
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='(' || x[i]=='[' || x[i]=='{')
        {
            string v(1,x[i]);
            s.push(v);
        }
        else if(x[i]==')' || x[i]==']' || x[i]=='}')
        {
            if(x[i]==')')
            {
                while(s.empty()==false && s.top() != "(")
                {
                    y+=s.top();
                    y+=" ";
                    s.pop();
                }
                if(!s.empty())
                    s.pop();
            }
            else if(x[i]==']')
            {
                while(s.empty()==false && s.top() != "[")
                {
                    y+=s.top();
                    y+=" ";
                    s.pop();
                }
                if(!s.empty())
                    s.pop();
            }
            else
            {
                while(s.empty()==false && s.top() != "{")
                {
                    y+=s.top();
                    y+=" ";
                    s.pop();
                }
                if(!s.empty())
                    s.pop();
            }
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/' || x[i]=='%' || x[i]=='^')
        {
            while(s.empty()==false && prec(x[i])<=prec(s.top()[0]))
            {
                y+=s.top();
                y+=" ";
                s.pop();
            }
            string v(1,x[i]);
            s.push(v);
        }
        else if(x[i-1]!='+' && x[i-1]!='-' && x[i-1]!='*' && x[i-1]!='/' && x[i-1]!='%' && x[i-1]!='^' && x[i-1]!='(' && x[i-1]!='[' && x[i-1]!='{' && x[i-1]!=')' && x[i-1]!=']' && x[i-1]!='}' && !isdigit(x[i]))
        {
            if(( x[i]>='a' && x[i]<='z' ) || (x[i]>='A' && x[i]<='Z'))
                goto q1;
            int g=i;
            string q="";
            bool f = true;
            while((x[g]!=' ' || f) && g!=0)
            {
                q+=x[g];
                g=g-1;
                f=false;
            }
            reverse(q.begin(),q.end());
            y+=q;
            if(q!="")
                y+=" ";
        }
        q1: continue;
    }
    while(!s.empty())
    {
        y+= s.top();
        y += " ";
        s.pop();
    }
    return y;
}


string infixtoPrefix(string x)
{
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='(')
            x[i]=')';
        else if(x[i]=='[')
            x[i]=']';
        else if(x[i]=='{')
            x[i]='}';
        else if(x[i]==']')
            x[i]='[';
        else if(x[i]==')')
            x[i]='(';
        else if(x[i]=='}')
            x[i]='}';
    }
    reverse(x.begin(),x.end());
    string a = infixToPostFix(x);
    reverse(a.begin(),a.end());
    return a;
}

string PostfixtoInfix(string x)
{
    stack<string> s;
    string v = "; ";
    v+=x+" ";
    for (int i=0;i<v.size();i++)
    {
        if(v[i-1]!='+' && v[i-1]!='-' && v[i-1]!='*' && v[i-1]!='/' && v[i-1]!='%' && v[i-1]!='^' && v[i-1]!=';' && v[i]!=';' && v[i]==' ' && v[i-1]!=' ')
        {
            int g=i;
            string q="";
            bool f = true;
            while((v[g]!=' ' || f) && g!=0)
            {
                q+=v[g];
                g=g-1;
                f=false;
            }
            reverse(q.begin(),q.end());
            s.push(q);
        }
        else if(v[i]=='+' || v[i]=='-' || v[i]=='*' || v[i]=='/' || v[i]=='%' || v[i]=='^')
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(" ( " + op2+" "+ v[i] +" "+ op1 + " ) ");
        }
    }
    return s.top();
}

string PrefixtoInfix(string x)
{
    stack<string> s;
    string v = "; ";
    v+=x+" ";
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(v[i-1]!='+' && v[i-1]!='-' && v[i-1]!='*' && v[i-1]!='/' && v[i-1]!='%' && v[i-1]!='^' && v[i-1]!=';' && v[i]!=';' && v[i]==' ' && v[i-1]!=' ')
        {
            int g=i;
            string q="";
            bool f = true;
            while((v[g]!=' ' || f) && g!=0)
            {
                q+=v[g];
                g=g-1;
                f=false;
            }
            s.push(q);
        }
        else if(v[i]=='+' || v[i]=='-' || v[i]=='*' || v[i]=='/' || v[i]=='%' || v[i]=='^')
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(" ( " + op1+" "+ v[i] +" "+ op2 + " ) ");
        }
    }
    return s.top();
}

string PostfixToPrefix(string x)
{
    stack<string> s;
    string v = "; ";
    v+=x+" ";
    for (int i=0;i<v.size();i++){
         if((v[i]=='+' || v[i]=='-' || v[i]=='*' || v[i]=='/' || v[i]=='%' || v[i]=='^')) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = string(1,v[i])+" "+op2+" "+op1;
            s.push(temp);
        }
        else if(v[i]==' ' && v[i-1]!='+' && v[i-1]!='-' && v[i-1]!='*' && v[i-1]!='/' && v[i-1]!='%' && v[i-1]!='^')
        {
            int g=i;
            string q="";
            bool f = true;
            while((v[g]!=' ' || f) && g!=0)
            {
                q+=v[g];
                g=g-1;
                f=false;
            }
            reverse(q.begin(),q.end());
            s.push(q);
        }
    }

    return s.top();
}

string PrefixtoPostfix(string x)
{
    stack<string> s;
    string v = "; ";
    v+=x+" ";
    reverse(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
         if(v[i]=='+' || v[i]=='-' || v[i]=='*' || v[i]=='/' || v[i]=='%' || v[i]=='^'){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1+" "+op2+" "+string(1,v[i]);
            s.push(temp);
        }
        else if(v[i]==' ' && v[i-1]!='+' && v[i-1]!='-' && v[i-1]!='*' && v[i-1]!='/' && v[i-1]!='%' && v[i-1]!='^' && v[i-1]!=' ' && v[i-1]!=';')
        {
            int g=i;
            string q="";
            bool f = true;
            while((v[g]!=' ' || f) && g!=0)
            {
                q+=v[g];
                g=g-1;
                f=false;
            }
            s.push(q);
        }
    }

    return s.top();
}
