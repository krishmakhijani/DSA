#include<stdio.h>
 struct student{
    int roll;
    char name[40];
 };
 int main(){
    int n;
    printf("ENTER THE NUMBER OF STUDENTS : ");
    scanf("%d",&n);
    struct student stu[n];
    for(int i=0;i<n;i++){
        printf("Enter student Roll no : ");
        scanf("%d",&stu[i].roll);
        printf("ENTER THE STUDENT NAME : ");
        scanf("%s",stu[i].name);
    }
    
    for(int i =0;i<n;i++){
        printf("\n");
        printf("%d : %s\n",stu[i].roll,stu[i].name);
    }
    
 }