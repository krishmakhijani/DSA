//linked list implementing findinglength insertathead insertattail insertatposition deletenode
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
void insertathead(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;
}
void insertattail(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    struct node* temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
}
void insertatposition(int x,int n)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(n==1)
    {
        temp->next=head;
        head=temp;
        return;
    }
    struct node* temp1=head;
    for(int i=0;i<n-2;i++)
    {
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}
void deletenode(int n)
{
    struct node* temp=head;
    if(n==1)
    {
        head=temp->next;
        free(temp);
        return;
    }
    for(int i=0;i<n-2;i++)
    {
        temp=temp->next;
    }
    struct node* temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}
void print()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int findlength()
{
    struct node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int main()
{
    head=NULL;
    insertathead(2);
    insertathead(4);
    insertattail(6);
    insertatposition(8,3);
    print();
    printf("\n");
    printf("AFTER DELETING NODE AT POSITION\n");
    deletenode(3);
    print();
  insertathead(4);
  insertattail(4);
}
