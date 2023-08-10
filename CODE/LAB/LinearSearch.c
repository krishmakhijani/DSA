#include <stdio.h>
int main(){
    int n,key,i;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i] == key){
            printf("Found at index %d", i);
            break;
        }
    }
    if(i == 10){
        printf("Not found\n");
    }
    return 0;
}