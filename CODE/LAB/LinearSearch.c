// arithmatic polynomial addition using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *newnode,*temp;
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of term %d: ",i+1);
        scanf("%d%d",&newnode->coeff,&newnode->exp);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->exp);
        temp=temp->next;
        if(temp!=NULL)
            printf(" + ");
    }
    printf("\n");
}

struct node *add(struct node *head1,struct node *head2,struct node *head3)
{
    struct node *temp1,*temp2,*temp3,*newnode;
    temp1=head1;
    temp2=head2;
    temp3=head3;
    while(temp1!=NULL && temp2!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(temp1->exp==temp2->exp)
        {
            newnode->coeff=temp1->coeff+temp2->coeff;
            newnode->exp=temp1->exp;
            newnode->next=NULL;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp>temp2->exp)
        {
            newnode->coeff=temp1->coeff;
            newnode->exp=temp1->exp;
            newnode->next=NULL;
            temp1=temp1->next;
        }
        else
        {
            newnode->coeff=temp2->coeff;
            newnode->exp=temp2->exp;
            newnode->next=NULL;
            temp2=temp2->next;
        }
        if(head3==NULL)
        {
            head3=newnode;
            temp3=head3;
        }
        else
        {
            temp3->next=newnode;
            temp3=newnode;
        }
    }
    while(temp1!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->coeff=temp1->coeff;
        newnode->exp=temp1->exp;
        newnode->next=NULL;
        temp1=temp1->next;
        temp3->next=newnode;
        temp3=newnode;
    }
    while(temp2!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->coeff=temp2->coeff;
        newnode->exp=temp2->exp;
        newnode->next=NULL;
        temp2=temp2->next;
        temp3->next=newnode;
        temp3=newnode;
    }
    return head3;
}

int main()
{
    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    printf("Enter the first polynomial:\n");
    head1=create(head1);
    printf("Enter the second polynomial:\n");
    head2=create(head2);
    printf("The first polynomial is: ");
    display(head1);
    printf("The second polynomial is: ");
    display(head2);
    head3=add(head1,head2,head3);
    printf("The sum of the two polynomials is: ");
    display(head3);
    return 0;
}