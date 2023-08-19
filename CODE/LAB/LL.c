#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}
void insertathead(struct Node* head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void inseratlast(struct Node* head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = head;
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}
void deletenode(struct Node* head, int key){
    struct Node *temp = head, *prev;
    if(temp != NULL && temp->data == key){
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main(){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    void insertathead(struct Node* head, int data);
    insertathead(&head, 4);
    void insertatlast(struct Node* head, int data);
    inseratlast(&head, 5);
    printList(head);
    printf("\n");
    return 0;
}


