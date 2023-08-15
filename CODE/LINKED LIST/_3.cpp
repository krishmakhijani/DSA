//INSERT
#include<iostream>
using namespace std;

class Node{
    public:
    int data ; 
    Node* next;
    Node(){
        this->data=0;
        this->next = NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void InsertatHead(Node* &head,Node* &tail,int data){ //INSERTING ELEMENT AT THE HEAD 
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    Node* newNode = new Node(data);
    newNode->next=head;
    head = newNode;
}
void InsertatTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next=newNode;
    tail=newNode;
    
}
void print(Node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }

};

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    InsertatHead(head,tail,20);
    InsertatHead(head,tail,30);
    InsertatHead(head,tail,40);
    InsertatHead(head,tail,50);
    InsertatHead(head,tail,60);
    InsertatTail(head,tail,10);
    print(head);
}