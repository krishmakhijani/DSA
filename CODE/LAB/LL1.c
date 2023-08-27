//double linked list implementing findinglength insertathead insertattail insertatposition deletenode
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void insertathead(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    temp->prev=NULL;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    head=temp;
    if(tail==NULL)
    {
        tail=temp;
    }
}
void insertattail(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=tail;
    if(tail!=NULL)
    {
        tail->next=temp;
    }
    tail=temp;
    if(head==NULL)
    {
        head=temp;
    }
}
void insertatposition(int x,int pos)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
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
    temp->prev=temp1;
    temp1->next=temp;
    temp1->next->prev=temp;
}
void deletenode(int pos)
{
    struct node *temp=head;
    if(pos==1)
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
        return;
    }
    for(int i=0;i<pos-2;i++)
    {
        temp=temp->next;
    }
    struct node *temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;
    free(temp1);
}
void print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int findlength()
{
    struct node *temp=head;
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
    insertathead(2);
    insertathead(4);
    insertathead(6);
    insertathead(8);
    insertathead(10);
    insertattail(12);
    insertattail(14);
    insertattail(16);
    insertattail(18);
    insertattail(20);
    insertatposition(22,3);
    insertatposition(24,5);
    insertatposition(26,7);
    insertatposition(28,9);
    insertatposition(30,11);
    deletenode(1);
    deletenode(3);
    deletenode(5);
    deletenode(7);
    deletenode(9);
    print();
    return 0;
}
