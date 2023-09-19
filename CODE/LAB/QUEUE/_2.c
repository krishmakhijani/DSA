//queue implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
        return;
    }
    rear->next=newnode;
    rear=newnode;
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    temp=front;
    front=front->next;
    printf("Element deleted is %d\n",temp->data);
    free(temp);
}

void display()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    temp=front;
    printf("Queue is\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
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
        }
    }
    return 0;
}
