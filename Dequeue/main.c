#include <stdio.h>
#define MAX 10

int front=-1,rear=-1;
int data[MAX];

int isFull()
{
    if((front == rear + 1) || (front==0 && rear==MAX-1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}


int addFront(int element)
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        if(front==-1 && rear==-1)
        {
            rear=0;
            front=0;
        }
        else
            front=(front+MAX-1)%MAX;
        data[front] = element;
    }
}

void addRear(int element)
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        if(front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        data[rear] = element;
    }
}

int delFront()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = data[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    return (element);
    }
}

int delRear()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element=data[rear];
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear+MAX-1)%MAX;
        }
    return (element);
    }
}

void display()
{

    int i;
    if (front==-1 && rear==-1)
        printf(" \n Empty Queue");
    else
    {
        printf("\n Items are: ");
        for (i = front; i!=rear; i=(i + 1)%MAX)
        {
            printf("%d ", data[i]);
        }
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    er3: printf("IN DEQUE QUEUE CHOOSE MODE\n\t\t1.INPUT RESTRICTED 2.OUTPUT RESTRICTED\n");
    printf("Enter the choice\n");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        int v=1;
        while(v==1)
        {
            er: printf("Operation supported 1.INSERTION AT REAR 2.DELETION AT FRONT 3.DELETION AT FRONT 4.DISPLAY\n\n\t\tEnter your choice\n");
            int u;
            scanf("%d",&u);
            if(u==1)
            {
                printf("Enter the element to be inserted at rear : ");
                int ga;
                scanf("%d",&ga);
                addRear(ga);
            }
            else if(u==2)
                delRear();
            else if(u==3)
                delFront();
            else if(u==4)
                display();
            else
            {
                printf("Invalid choice Enter once again\n");
                goto er;
            }
            printf("Enter 1 to continue : ");
            scanf("%d",&u);
        }
    }
    else if(x==2)
    {
        int v=1;
        while(v==1)
        {
            er1: printf("Operation supported 1.INSERTION AT REAR 2.INSERTION AT FRONT 3.DELETION AT FRONT 4.DISPLAY\n\n\t\tEnter your choice\n");
            int u;
            scanf("%d",&u);
            if(u==1)
            {
                printf("Enter the element to be inserted at rear : ");
                int ga;
                scanf("%d",&ga);
                addRear(ga);
            }
            else if(u==2)
            {
                printf("Enter the element to be inserted at front : ");
                int ga;
                scanf("%d",&ga);
                addFront(ga);
            }
            else if(u==3)
                delFront();
            else if(u==4)
                display();
            else
            {
                printf("Invalid choice Enter once again\n");
                goto er1;
            }
            printf("Enter 1 to continue : ");
            scanf("%d",&v);
        }
    }
    else
    {
        printf("Invalid choice Enter once again\n");
        goto er3;
    }
}
