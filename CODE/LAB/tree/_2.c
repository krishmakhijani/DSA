#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void insert(int data)
{
    struct node *newNode = createNode(data);
    if(root == NULL)
    {
        root = newNode;
        return;
    }
    struct node *temp = root;
    while(1)
    {
        if(data < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

void inorder(struct node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

void preorder(struct node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    printf("%d ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}


int main()
{
    int choice;
    int data;
    while(1)
    {
        printf("Enter the choice\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data\n");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
        }
    }
}
