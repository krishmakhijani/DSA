#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;
void enqueue(int data){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
    }
    if(front-rear == 1 || rear-front == MAX-1){
        printf("Queue is full\n");
    }
    else{
        rear = (rear+1)%MAX;
        queue[rear] = data;}
    printf("REAR IS : %d\n",rear);
}

int dequeue(){
    int temp;
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return -1;
    }
    if(front == rear){
        temp = queue[front];
        front = rear = -1;
    }
    else{
        
        temp = queue[front];
        front = (front+1)%MAX;
}

    printf("FRONT IS : %d\n",front);
    return temp;
}

void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: ");
        for(i=front;i!=rear;i=(i+1)%MAX){
            printf("%d ",queue[i]);
        }
        printf("%d",queue[i]);
        printf("\n FRONT IS : %d\n",front);
        printf("\n REAR IS : %d\n",rear);
    }

}

int main()
{
    int ch,item;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: item=dequeue();
                    if(item==-1)
                        printf("Queue is empty\n");
                    else
                        printf("Deleted element is %d\n",item);
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}