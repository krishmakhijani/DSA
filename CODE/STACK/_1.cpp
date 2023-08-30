#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(70);
    st.push(60);
    st.push(32);

    st.pop();

    cout << "Element on top " << st.top() << endl;
    cout<< "Size : "<< st.size()<<endl;
    if(st.empty())
    cout<< "STACK IS EMPTY";
    else
    cout << "Not Empty";
}