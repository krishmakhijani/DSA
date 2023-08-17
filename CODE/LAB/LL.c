#include <stdio.h>
struct student
{
char *c;
struct student *point;
};
void main()
{
struct student s;
struct student *m = &s;
printf("%d",sizeof(student));}
