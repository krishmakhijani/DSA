#include<iostream>
using namespace std;

int resverse(int n , int arr[]){
    int low;
    for(int i=0;i<n/2;i++){
        low = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = low;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    resverse(n,arr);
    return 0;
}