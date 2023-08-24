#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int top;
    int size;
    int *arr;
    Stack(int size){
        arr = new int[size];
        this->size=size;
        this->top=-1;

    }

    //functions

    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"STACK OVERFLOW";
        }
    }

    void pop(){
        if(top==-1){
            cout<<"UNDERFLOW";
        }
        else{
            top--;
        }
    }

    void getTop(){
        if(top==-1){
            cout<<"STACK IS EMPTY";
        }
        else{
            cout << arr[top] << endl;
        }
    }
    int getSize(){
        // Number of elements in stack is top + 1
        return top + 1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack s(10);
    // Insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // Printing stack
    while(!s.isEmpty()){
        s.getTop();
        s.pop();
    }
    // Checking size
    cout<<"Size of stack = "<<s.getSize()<<endl;
    // Checking empty or not
    if(s.isEmpty()){
        cout<<"Stack empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}