#include<iostream>
using namespace std;
int main(){
    int N,i,j;
    cin>>N;
    for(i=1; i<=N; i++){
        int temp = i%2;
        for(j=1;j<=i;j++){    
            if(i%2==0){ temp +=2;
                cout<<temp<<" ";
            }
            else{cout<<temp<<" ";
                temp+=2;
            }
        }
        cout<<endl;
    }
}