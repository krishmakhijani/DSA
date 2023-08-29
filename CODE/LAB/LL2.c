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
void print()
{
    struct node *temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
int main()
{
    insertathead(2);
    insertathead(4);
    insertathead(6);
    insertathead(8);
    insertathead(10);
    print();
    insertattail(12);
    insertattail(14);
    insertattail(16);
    insertattail(18);
    insertattail(20);
    print();
    insertatposition(22,1);
    insertatposition(24,3);
    insertatposition(26,5);
    insertatposition(28,7);
    insertatposition(30,9);
    print();
    deleteatposition(1);
    deleteatposition(2);
    deleteatposition(3);
    deleteatposition(4);
    deleteatposition(5);
    print();
    return 0;
}