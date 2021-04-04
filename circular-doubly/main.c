#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* create(struct Node** head)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Number of elements: ");
    int n;
    scanf("%d",&n);
    scanf("%d",&temp->data);
    *head=temp;
    temp->next=temp->prev=temp;
    struct Node* last=temp;
    for(int i=1;i<n;i++)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&temp->data);
        temp->next=last->next;
        temp->prev=last;
        last->next=temp;
        last=temp;
        (*head)->prev=temp;
    }
    return *head;
};

void display(struct Node** head)
{
    struct Node* temp = *head;
    int i=0;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=*head);
}


struct Node* insert(struct Node** head)
{
    printf("\nEnter the position where you want to insert: ");
    int n;
    scanf("%d",&n);
    printf("\nEnter the element you want to insert: ");
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&temp->data);
    if(n==1)
    {
        if(*head==NULL)
        {
            *head=temp;
            temp->next=temp;
            temp->prev=temp;
        }
        else
        {
            struct Node* temp1 =*head;
            temp->next=*head;
            temp->prev=temp1->prev;
            temp1->prev->next=temp;
            temp1->prev=temp;
            (*head)=temp;
        }
    }
    else
    {
        struct Node* temp1 =*head;
        for(int i=0;i<n-2;i++)
            temp1=temp1->next;
        temp->next=temp1->next;
        temp->prev=temp1;
        temp1->next->prev=temp;
        temp1->next=temp;
    }
    return *head;
};


struct Node* Delete(struct Node** head)
{
    printf("Enter position to be delete: ");
    int pos;
    scanf("%d",&pos);
    struct Node* temp =*head;
    if(pos==1)
    {
        if(temp->next==temp)
        {
            free(temp);
            *head=NULL;
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            *head=temp->next;
            free(temp);
        }
    }
    else
    {
        for(int i=0;i<pos-2;i++)
            temp=temp->next;
        struct Node* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next->prev=temp;
        free(temp1);
    }
};

int main()
{
    struct Node* head =NULL;
    create(&head);
    display(&head);
    Delete(&head);
    display(&head);
}
