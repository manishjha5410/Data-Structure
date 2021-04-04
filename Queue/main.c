#include <stdio.h>
#define SIZE 5

int data[SIZE];
int front = -1, rear = -1;

int isFull()
{
    if((front == rear + 1) || (front==0 && rear==SIZE-1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enQueue(int element)
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        data[rear] = element;
    }
}

int deQueue()
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
            front = (front + 1) % SIZE;
        }
    return (element);
    }
}

void display()
{
    int i;
    if (isEmpty())
        printf(" \n Empty Queue");
    else
    {
        printf("\n Items are: ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", data[i]);
        }
        printf("%d ", data[i]);
    }
}

int main()
{
    int c=1;
    while(c==1)
    {
        g: printf("IN CIRCULAR QUEUE THIS OPERATION CAN BE DONE\n1.INSERTION 2.DELETION 3.DISPLAY\n");
        printf("Enter the choice\n");
        int x;
        scanf("%d",&x);
        if(x==1)
        {
            printf("Enter element to insert\n");
            int a;
            scanf("%d",&a);
            enQueue(a);
        }
        else if(x==2)
        {
           deQueue();
        }
        else if(x==3)
        {
            display();
        }
        else
        {
            printf("INVALID CHOICE ENTER ONCE AGAIN\n");
            goto g;
        }
        printf("Enter 1 to continue else for exit\n");
        scanf("%d",&c);
    }
}
