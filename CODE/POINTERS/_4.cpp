#include<iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    
}