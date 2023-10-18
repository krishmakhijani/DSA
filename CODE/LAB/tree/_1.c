#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int tree[MAX] = {0};

void insert(int data, int parent, int child)
{
    if(tree[parent] == 0)
    {
        printf("Parent not found\n");
        return;
    }
    if(tree[child] != 0)
    {
        printf("Child already exists\n");
        return;
    }
    tree[child] = data;
}

void display(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the choice\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Exit\n");
    int choice;
    int data, parent, child;
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data, parent and child\n");
                scanf("%d %d %d", &data, &parent, &child);
                insert(data, parent, child);
                break;
            case 2:
                display(10);
                break;
            case 3:
                exit(0);
        }
    }
}
