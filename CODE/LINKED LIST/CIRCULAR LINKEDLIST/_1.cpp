//singlycircular linked list implementation

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* head){
    Node* temp = head;
    if(head != NULL){
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
    }
}

