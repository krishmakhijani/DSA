#include<stdio.h>

struct student{
    int roll;
    char name[40];
};

int main(){
    struct student stu1;
    struct student *stu2;
    stu2 = &stu1;

        printf("Enter student Roll no : ");
        scanf("%d",&stu2->roll);
        printf("ENTER THE STUDENT NAME : ");
        scanf("%s",stu2->name);

    
        printf("\n");
        printf("%d : %s\n",stu2->roll,stu2->name);
}