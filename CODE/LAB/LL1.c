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
    insertattail(12);
    insertattail(14);
    insertatposition(22,3);
    printf("BEFORE DELETE\n");
    print();
    deletenode(1);
    deletenode(3);
    printf("\n");
    printf("AFTER DELETE\n");
    print();
    printf("\n");
    return 0;
}

