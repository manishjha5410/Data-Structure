#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct node* next;
};

struct Node** Create(struct Node** head)
{
    printf("Enter number of element: ");
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    *head = temp1;
    struct Node* temp2 = *head;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&x);
        struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
        temp1->data=x;
        temp1->next=NULL;
        temp2->next=temp1;
        temp2=temp2->next;
    }
    return *head;
};

void print(struct Node** head)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1=*head;
    printf("List: \n");
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}

struct Node** InsertBefore(struct Node** head)
{
    int n,x;
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 = *head;
    printf("%d \n",temp1->data);
    printf("Enter the element before which to insert: ");
    scanf("%d",&n);
    printf("Enter the element: ");
    scanf("%d",&x);
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp2->data=x;
    temp2->next=NULL;
    while(temp1!=NULL)
    {
        if(temp1->data == n)
        {
            temp2->next = temp1;
            *head = temp2;
            break;
        }
        else
        {
            struct Node *newtemp = temp1->next;
            if(newtemp->data == n && temp1->next!=NULL)
            {
                temp2->next = temp1->next;
                temp1->next = temp2;
                break;
            }
            temp1 = temp1->next;
        }
    }
    if(temp1==NULL)
    {
        printf("Element not found \n");
    }
    return *head;
}

struct Node** InsertAfter(struct Node** head)
{
    int n,x;
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 = *head;
    printf("%d \n",temp1->data);
    printf("Enter the element after which to insert: ");
    scanf("%d",&n);
    printf("Enter the element: ");
    scanf("%d",&x);
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp2->data=x;
    temp2->next=NULL;
    while(temp1!=NULL)
    {
        if(temp1->data==n)
        {
            temp2->next = temp1->next;
            temp1->next=temp2;
            break;
        }
        temp1=temp1->next;
    }
    if(temp1==NULL)
    {
        printf("Element not found \n");
    }
    return *head;
}
struct Node** InsertByPosition(struct Node** head)
{
    int n,x;
    struct Node* temp1 = *head;
    printf("Enter the number to be inserted: ");
    scanf("%d",&n);
    printf("Enter the position: ");
    scanf("%d",&x);
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp2->data=n;
    temp2->next=NULL;
    for(int i=0;i<x-2;i++)
        temp1=temp1->next;
    if(n>Length(&(*head)))
    {
        printf("Wrong position entered\n");
    }
    else if(x==1)
    {
        temp2->next=*head;
        *head=temp2;
    }
    else
    {
        temp2->next=temp1->next;
        temp1->next=temp2;
    }
    return *head;
}

struct Node** Insert(struct Node** head)
{
    int h;
    j: printf("Choose which you want to do: \n1. Insert before 2. Insert after 3. Insert by position\n");
    scanf("%d",&h);
    switch(h)
    {
        case 1:
            *head = InsertBefore(&(*head));
            break;
        case 2:
            *head = InsertAfter(&(*head));
            break;
        case 3:
            *head = InsertByPosition(&(*head));
            break;
        default:
            printf("Wrong input\n Enter once again\n");
            goto j;
    }
    return *head;
};

struct Node** DeleteValue(struct Node** head)
{
    int n;
    struct Node* temp1 = *head;
    printf("Enter the number to be deleted: ");
    scanf("%d",&n);
    struct Node* temp2;
    temp2=temp1->next;
    if(temp1->data == n)
    {
        *head = temp1->next;
        free(temp1);
    }
    else
    {
        while(temp2->next!=NULL)
        {
            temp2 = temp1->next;
            if(temp2->data == n && temp2!=NULL)
            {
                temp1->next=temp2->next;
                free(temp2);
                goto h;
            }
            temp1 = temp1->next;
        }
    }
    if(temp2->next==NULL)
        printf("Element not found \n");
    h: return *head;
}

struct Node** DeletePosition(struct Node** head)
{
    int n,x;
    struct Node* temp1 = *head;
    printf("Enter the position from which value to be deleted: ");
    scanf("%d",&n);
    struct Node* temp2;
    for(int i=0;i<n-2;i++)
        temp1=temp1->next;
    temp2=temp1->next;
    if(n>Length(&(*head)))
    {
        printf("Wrong position Entered\n");
    }
    else if(n==1)
    {
        *head=temp1->next;
        free(temp1);
    }
    else
    {
       temp1->next=temp2->next;
    }
    return *head;
}

struct Node** Delete(struct Node** head)
{
    int h;
    j: printf("Choose which you want to do: \n1. Delete By Value 2.Delete By Position\n");
    scanf("%d",&h);
    switch(h)
    {
        case 1:
            *head = DeleteValue(&(*head));
            break;
        case 2:
            *head = DeletePosition(&(*head));
            break;
        default:
            printf("Wrong input\n Enter once again\n");
            goto j;
    }
    return *head;
}

int Length(struct Node** head)
{
    struct Node* temp1 = *head;
    int c=0;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        c++;
    }
    return c;
}

int duplicate(struct Node** head)
{
    Node *p,*q;
    p=*head;
    q=p->next;
    while(q!=NULL)
    {
        if(p->data==q->data)
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
    }
}

void loop(Node** head)
{
    Node *p,*q;
    p=q=*head;
    while(p&&q)
    {
       p=p->next;
       q=q->next->next;
       if(p==q)
       {
           cout<<"loop Found"<<endl;
           p=*head;
           while(p->next!=q->next)
           {
               p=p->next;
               q=q->next;
           }
           q->next=NULL;
       }
       if(q==NULL || q->next==NULL)
       {
           cout<<"loop Not found"<<endl;
           break;
       }
    }
}

Node* Merge(Node** h1,Node** h2)
{
    Node *p,*q,*r,*h3,*r1;
    p=*h1,q=*h2;
    r = (Node*)malloc(sizeof(Node));
    r->next=NULL;
    h3=r;
    r1=h3;
    if(p->data>q->data)
    {
        r1->data=q->data;
        q=q->next;
    }
    else
    {
        r->data=p->data;
        p=p->next;
    }
    while(p!=NULL && q!=NULL)
    {
        r = (Node*)malloc(sizeof(Node));
        r->next=NULL;
        if(p->data>q->data)
        {
            r1->next=r;
            r->data=q->data;
            r1=r1->next;q=q->next;
        }
        else
        {
            r1->next=r;
            r->data=p->data;
            r1=r1->next;p=p->next;
        }
    }
    if(p!=NULL)
        r1->next=p;
    if(q!=NULL)
        r1->next=q;
    return h3;
}


struct Node** swap(struct Node** head)
{
    int n,m,c1=0,c2=0;
    printf("Enter the two value in List: ");
    scanf("%d %d",&m,&n);
    struct Node *temp1,*temp2;
    temp1=*head;temp2=*head;
    while(temp1!=NULL && temp1->data!=m)
    {
        temp1=temp1->next;
        c1++;
    }
    while(temp2!=NULL && temp2->data!=n)
    {
        temp2=temp2->next;
        c2++;
    }
    if(temp1==NULL || temp2==NULL)
        printf("Wrong elements are entered\n");
    else
        swapElement(c1,c2,&(*head));
    return *head;
}

int swapElement(int m,int n,struct Node** head)
{
    int i;
    struct Node *temp1,*temp2;
    temp1=*head;temp2=*head;
    for(i=0;i<m;i++)
        temp1=temp1->next;
    for(i=0;i<n;i++)
        temp2=temp2->next;
    int t=temp2->data;
    temp2->data=temp1->data;
    temp1->data=t;
    return *head;
}

int getElement(struct Node** head,int j)
{
    struct Node *temp1;
    temp1=*head;
    for(int i=0;i<j;i++)
        temp1=temp1->next;
    return temp1->data;
}

int Middle(struct Node** head)
{
    struct Node* p = *head,*q=(*head)->next;
    while(q)
    {
        q=q->next;
        if(q)
        {
            q=q->next;
            p=p->next;
        }
    }
    return p->data;
}

int main()
{
    struct Node* head = NULL;
    head = Create(&head);
    print(&head);
    head = swap(&head);
    print(&head);
    printf("The middle element is: %d",Middle(&head));
    //head = BubbleSort(&head);
    //print(&head);
}
