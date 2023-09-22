#include<stdio.h>
#include<stdlib.h>

struct Ournode{
char x,Y,Z;
};

int main(){
    struct Ournode p = {1, '0', 'a'+2};
struct Ournode *q = &p;
printf ("%c, %c", *((char*)q+1), *((char*)q+2));
return 0;
}

