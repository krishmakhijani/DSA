#include<iostream>
using namespace std;
int main(){
    int N,i,temp,j;
    cin>>N;
    for(i=1; i<=N; i++){
        if(i%2==0)
            temp=2;
        else
            temp=1;
        for(j=1;j<=i;j++){    
            cout<<temp<<" ";
            temp+=2;
        }
        cout<<endl;
    }
}