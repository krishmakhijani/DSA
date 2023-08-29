// impelementattion of singly circular linked list


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void insertathead(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    if(head==NULL)
    {
        tail=temp;
        temp->next=head;
    }
    else
    {
        tail->next=temp;
    }
    head=temp;
}
void insertattail(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
    }
    else
    {
        tail->next=temp;
    }
    tail=temp;
}
void insertatposition(int x,int pos)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(pos==1)
    {
        insertathead(x);
        return;
    }
    struct node *temp1=head;
    for(int i=0;i<pos-2;i++)
    {
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}
void deleteathead()
{
    struct node *temp=head;
    head=head->next;
    tail->next=head;
    free(temp);
}
void deleteattail()
{
    struct node *temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=head;
    tail=temp;
    free(temp->next);
}
void deleteatposition(int pos)
{
    struct node *temp=head;
    if(pos==1)
    {
        deleteathead();
        return;
    }
    for(int i=0;i<pos-2;i++)
    {
        temp=temp->next;
    }
    struct node *temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}