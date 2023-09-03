#include<stdio.h>

void checkeven(int n){
    if(n%2==0){
        printf("Even");
    }
    else{
        printf("Odd");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    checkeven(n);
    return 0;
}