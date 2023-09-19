//queue implementation using arrays

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=x;
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted is %d\n",queue[front]);
    if(front==rear)
        front=rear=-1;
    else
        front++;
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is\n");
    for(i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
    printf("\n");
}

int main()
{
    int ch,x;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
