#include<stdio.h>
void main() {
int a[] = {5,7,3,2,4}, *p; p = a;
++*p;
printf("%d ", *p);
p += 3;
printf("%d ", *p);
}