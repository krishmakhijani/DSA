//stack implementation using linked lists
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = top;
    top = temp;
}
int pop() {
    struct node *temp;
    int data;
    if(top == NULL) {
    printf("Stack underflow\n");
    return -1;
    }
    temp = top;
    top = top->next;
    data = temp->data;
    free(temp);
    return data;
}
void display() {
    struct node *temp;
    if(top == NULL) {
    printf("Stack is empty\n");
    return;
    }
    temp = top;
    while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
    }
    printf("\n");
}
void main() {
    int ch, data;
    while(1) {
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch) {
    case 1: printf("Enter data: ");
    scanf("%d", &data);
    push(data);
    break;
    case 2: data = pop();
    if(data != -1)
    printf("Popped data is %d\n", data);
    break;
    case 3: display();
    break;
    case 4: exit(0);
    default: printf("Invalid choice\n");
    }
    }
}

