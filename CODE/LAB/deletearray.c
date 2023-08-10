//deletion operation on array at index
#include <stdio.h>

int main(){
    int n,i,index;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the index at which you want to delete: ");
    scanf("%d",&index);
    
    for(i=index;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    n--;
    printf("The new array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}