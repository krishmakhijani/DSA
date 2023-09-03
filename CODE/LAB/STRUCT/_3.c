 struct student{
    int roll;
    char name[40];
 };
struct student1{
    char name[40];
    struct student stu;
 };

 int main(){
    struct student1 str[5];
    for(int i=0;i<5;i++){
        printf("Enter student Roll no : ");
        scanf("%d",&str[i].stu.roll);
        printf("ENTER THE STUDENT NAME : ");
        scanf("%s",str[i].name);
    }
    
    for(int i =0;i<5;i++){
        printf("\n");
        printf("%d : %s\n",str[i].stu.roll,str[i].name);
    }
 }