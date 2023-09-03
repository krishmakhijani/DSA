#include<stdio.h>
 struct student{
    int roll;
    char name[40];
 };

 int main(){
    struct student student1;
    printf("Enter student Roll no : ");
    scanf("%d",&student1.roll);
    printf("ENTER THE STUDENT NAME : ");
    scanf("%s",student1.name);
    printf("\n");
    printf("%d : %s\n",student1.roll,student1.name);
 }