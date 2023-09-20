// stack implementation using array

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int);
int pop();
int peek();
void display();

int main()
{
    int choice, val;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
                printf("The deleted element is %d\n", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("The first value in stack is %d\n", val);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong selection!!! Try again!!!");
        }
    }
    return 0;
}

void push(int val)
{
    if (top == MAX - 1)
        printf("\nStack is full!!! Insertion is not possible!!!");
    else
    {
        top++;
        stack[top] = val;
        printf("\nInsertion success!!!");
    }
}

int pop()
{
    int val;
    if (top == -1)
        printf("\nStack is empty!!! Deletion is not possible!!!");
    else
    {
        val = stack[top];
        top--;
        return val;
    }
    return -1;
}

int peek()
{
    if (top == -1)
    {
        printf("\nStack is empty!!!");
        return -1;
    }
    else
        return stack[top];
}

void display()
{
    int i;
    if (top == -1)
        printf("\nStack is empty!!!");
    else
    {
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

