#include <bits/stdc++.h>
using namespace std;

struct Poly
{
    int data;
    int pow;
    Poly* next;
};

void create(struct Poly** head)
{
    Poly *poly= new Poly(),*last;
    int n;
    printf("Enter number of polynomial terms\n");
    scanf("%d",&n);
    printf("Enter polynomial term followed by expression\n");
    scanf("%d%d",&poly->data,&poly->pow);
    poly->next=NULL;
    *head=last=poly;
    for(int i=1;i<n;i++)
    {
        Poly *poly= new Poly();
        scanf("%d%d",&poly->data,&poly->pow);
        poly->next=NULL;
        last->next=poly;
        last=poly;
    }
}

Poly* Add(Poly** head1,Poly **head2)
{
    Poly *p=*head1,*q=*head2,*head,*last;
    Poly *r = new Poly();
    head=last=r;
    r->next=NULL;
    if(p->pow>q->pow)
    {
        r->pow=q->pow;
        r->data=q->data;
    }
    else if(q->pow>p->pow)
    {
        r->pow=p->pow;
        r->data=p->data;
    }
    else
    {
        r->pow=p->pow;
        r->data=p->data+q->data;
    }
    p=p->next;q=q->next;
    while(p!=NULL && q!=NULL)
    {
        Poly *r = new Poly();
        r->next=NULL;
        last->next=r;
        last=r;
        if(p->pow>q->pow)
        {
            r->pow=q->pow;
            r->data=q->data;
        }
        else if(q->pow>p->pow)
        {
            r->pow=p->pow;
            r->data=p->data;
        }
        else
        {
            r->pow=p->pow;
            r->data=p->data+q->data;
        }
        p=p->next;q=q->next;
    }
    while(p)
    {
        Poly *r = new Poly();
        last->next=r;
        last=r;
        r->data=p->data;
        r->pow=p->pow;
        p=p->next;
    }
    while(q)
    {
        Poly *r = new Poly();
        last->next=r;
        last=r;
        r->data=q->data;
        r->pow=q->pow;
        q=q->next;
    }
    return head;
};

void Display(struct Poly** head)
{
    Poly *p=*head;
    while(p)
    {
        if(p->next==NULL)
            printf("%dx^%d ",p->data,p->pow);
        else
            printf("%dx^%d+",p->data,p->pow);
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    Poly* head1= NULL,*head2=NULL,*head;
    create(&head1);
    Display(&head1);
    create(&head2);
    Display(&head2);
    head=Add(&head1,&head2);
    Display(&head);
}
