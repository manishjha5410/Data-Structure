#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next,*prev;
};

struct Node* create(struct Node **head)
{
    printf("Enter number of elements: ");
    int n;
    scanf("%d",&n);
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->next=NULL;
    temp->prev=NULL;
    scanf("%d",&temp->data);
    *head=temp;
    struct Node* last=temp;
    for(int i=1;i<n;i++)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }
    return *head;
};

void display(struct Node **head)
{
    struct Node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct Node* Reverse(struct Node** head)
{
    struct Node *temp=*head,*temp1;
    while(temp!=NULL)
    {
        temp1=temp->next;
        temp->next=temp->prev;
        temp->prev=temp1;
        temp=temp->prev;
        if(temp!=NULL && temp->next==NULL)
            *head=temp;
    }
    return *head;
};


struct Node* Insert(struct Node** head)
{
    printf("Enter position to be inserted: ");
    int pos;
    scanf("%d",&pos);
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->next=temp->prev=NULL;
    printf("Enter data to be inserted: ");
    scanf("%d",&temp->data);
    if(pos==1)
    {
        if(*head==NULL)
        {
            *head=temp;
        }
        else
        {
            temp->next=*head;
            (*head)->prev=temp;
            *head=temp;
        }
    }
    else
    {
        struct Node *current = *head;
        for(int i=1;i<pos-1;i++)
            current=current->next;
        temp->next=current->next;
        current->next=temp;
        temp->prev=current;
        if(temp->next)
        {
            current=temp->next;
            current->prev=temp;
        }
    }
    return *head;
};

struct Node* Delete(struct Node** head)
{
    printf("Enter position to be delete: ");
    int pos;
    struct Node *temp=*head;
    scanf("%d",&pos);
    if(pos==1)
    {
        if((*head)->next==NULL)
        {
            free(*head);
            *head=NULL;
        }
        else
        {
            temp=(*head)->next;
            free(*head);
            temp->prev=NULL;
            *head=temp;
        }
    }
    else
    {
        for(int i=1;i<pos-1;i++)
            temp=temp->next;
        struct Node* last = temp->next;
        temp->next=last->next;
        if(temp->next)
            last->prev=temp;
        free(last);
    }

    return *head;
};

int main()
{
    struct Node* head = NULL;
    create(&head);
    display(&head);
   // Insert(&head);
    //display(&head);
    Delete(&head);
    display(&head);
}
