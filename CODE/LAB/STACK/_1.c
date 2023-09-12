#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top = -1, stack[MAX];
void push(int data) {
    if(top == MAX-1) {
    printf("Stack overflow\n");
    return;
    }
    stack[++top] = data;
}
int pop() {
    if(top == -1) {
    printf("Stack underflow\n");
    return -1;
    }
    return stack[top--];
}
void display() {
    int i;
    if(top == -1) {
    printf("Stack is empty\n");
    return;
    }
    for(i=top; i>=0; i--)
    printf("%d ", stack[i]);
    printf("\n");
}
void peak(){
    if(top == -1) {
    printf("Stack is empty\n");
    return;
    }
    printf("%d\n",stack[top]);
}
void main() {
    int ch, data;
    while(1) {
    printf("1. Push\n2. Pop\n3. Display\n4. Peak\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch) {
    case 1:
    printf("Enter data to be inserted: ");
    scanf("%d", &data);
    push(data);
    break;
    case 2:
    data = pop();
    if(data != -1)
    printf("Deleted element is %d\n", data);
    break;
    case 3:
    display();
    break;
    case 4:
    peak();
    break;
    case 5:
    exit(0);
    default:
    printf("Invalid choice\n");
    }
    }
}
