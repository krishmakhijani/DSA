//infix post fix using stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char item)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i, j;
    char item;
    char x;
    push('(');
    strcat(infix, ")");
    i = 0;
    j = 0;
    item = infix[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("Invalid infix expression.\n");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    if (top > 0)
    {
        printf("Invalid infix expression.\n");
        exit(1);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    gets(infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: ");
    puts(postfix);
    return 0;
}