#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        this->data=0;
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
int findlength(Node* &head){
    int len=0;
    Node* temp =head;
    while (temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
    }
}
void insertathead(int data,Node* &head,Node* &tail){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        return;
    } 
    Node* temp;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
}
int main(){
    Node* head;
    Node* tail;
    head->next=tail;
    tail->prev=head;
    insertathead(8,head,tail);
    print(head);
}