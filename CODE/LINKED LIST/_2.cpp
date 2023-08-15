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

void InsertatHead(Node* &head,int data){ //INSERTING ELEMENT AT THE HEAD 
    Node* newNode = new Node(data);
    newNode->next=head;
    head = newNode;
}
void print(Node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }

};

int main(){
    Node* head = new Node(10);
    InsertatHead(head,20);
    InsertatHead(head,30);
    InsertatHead(head,40);
    InsertatHead(head,50);
    InsertatHead(head,60);
    print(head);
}