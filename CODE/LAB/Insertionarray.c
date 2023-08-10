//Insertion in array at index
#include <stdio.h>

int main(){
    int n,key,i,index;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to be inserted: ");
    scanf("%d",&key);
    printf("Enter the index at which you want to insert: ");
    scanf("%d",&index);
    
    for(i=n-1;i>=index;i--){
        arr[i+1] = arr[i];
    }
    n++;
    arr[index] = key;
    printf("The new array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
