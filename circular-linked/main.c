#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node** create(struct Node** head)
{
    printf("Enter Number of elements: ");
    int n;
    scanf("%d",&n);
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    struct Node* last;
    temp->next=NULL;
    scanf("%d",&temp->data);
    (*head)=temp;
    (*head)->next=temp;
    last=temp;
    for(int i=1;i<n;i++)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->next=NULL;
        scanf("%d",&temp->data);
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
    return *head;
};

struct Node* insert(struct Node** head)
{
    printf("Enter the position where you want to insert: ");
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
        }
        else
        {
            struct Node* temp1=*head;
            do
            {
                temp1=temp1->next;
            }while(temp1!=*head);
            temp->next=temp1->next;
            temp1->next=temp;
            *head=temp;
        }
    }
    else
    {
        struct Node* temp1=*head;
        for(int i=0;i<n-1;i++)
            temp1=temp1->next;
        temp->next=temp1->next;
        temp1->next=temp;
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

int main()
{
    struct Node* head=NULL;
    create(&head);
    insert(&head);
    display(&head);
}
