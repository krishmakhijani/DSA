#include <stdio.h>
int main(){
    int *p = (int*)malloc(sizeof(int));
    p=NULL;
    free(p);
}