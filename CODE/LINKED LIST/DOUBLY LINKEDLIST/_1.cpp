#include<bits/stdc++.h>
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
    else{
        Node* newNode = new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;
    }
    
}
void InseratPositon(Node* &head,Node* &tail,int data,int index){
    if(head==NULL){
        Node* newNode = new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        tail=newNode;
    }
    else{
        if(index==1){
            InsertatHead(head,tail,data);
            return;
        }
        int len=getLength(head);
        if(index>len){
            InsertatTail(head,tail,data);
            return;
        }
        int i=1;
        Node* prevNode = head;
        while(i<index-1){
            prevNode=prevNode->next;
            i++;
        }
        Node* currNode=prevNode->next;
        Node* newNode= new Node(data);
        prevNode->next=newNode;
        newNode->prev=prevNode;
        newNode->next=currNode;
        currNode->prev=newNode;
    }
}

void deletefromposition(Node* &head,Node* &tail,int index){
    if(head==NULL){
        cout<<"NOT POSSIBLE";
        return;
    }
    int len=getLength(head);
    if(index>len){
        cout<<"NOT POSSIBLE";
        return;
    }
    if(index==1){
        Node* temp =head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete(temp);
        return;
    }
    if(index==len){
        Node* temp=tail;
        tail=tail->prev;
        temp->prev=NULL;
        temp->next=NULL;
        delete(temp);
        return;
    }
        Node* temp= head;
        int i=1;
        Node* left=head;
        while (i<index-1)
        {
            left=left->next;
            i++;
        }
        Node* curr = left->next;
        Node* right = curr->next;
        left->next=right;
        right->prev=left;
        curr->next=NULL;
        curr->prev=NULL;
        delete(curr);
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = new Node(200);
    Node* tail= new Node(300);
    InsertatHead(head,tail,100);
    head->next=first;
    first->prev=head;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev= second;
    third->next=tail;
    tail->prev=third;
    print(head); 
    cout<<"\n";
    InsertatTail(head,tail,77);
    print(head);
    cout<<endl;
    InseratPositon(head,tail,800,2);
    print(head);
    cout<<endl;
    deletefromposition(head,tail,2);
    print(head);
     
}