#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
 
int getLength(Node* &head){
    Node* temp = head;
    int len =0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void InsertatHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        tail=newNode;
    }
    Node* newNode = new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void InsertatTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        tail=newNode;
    }
    Node* newNode = new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail = newNode;
}


int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Node* head;
    Node* tail;
    InsertatTail(head,tail,77);
    
    head->next=first;
    first->prev=head;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev= second;
    print(head);
    InsertatHead(head,tail,100);
    print(head);
    
     
}