//33158

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#define MAX 50
#define cini(x)  scanf("%d",&x);
#define cins(x)  scanf("%s",x);
typedef struct student{
    int sid;
    int marks;
    char sname[MAX];   
}student;

char filename[]="file.txt";

void insert()
{
    student s;
    printf("\nEnter the name of student ::");cins(s.sname);
    printf("\nEnter the marks of student ::");cini(s.marks);
    printf("\nEnter the id of student ::");cini(s.sid);
    int fd=open(filename, O_WRONLY | O_CREAT |O_APPEND,0666);
    write(fd,&s,sizeof(s));
    close(fd);
}

void display()
{
    student s;
    int fd=open(filename,O_RDONLY,0666);
    if(fd==-1){printf("Error"); return;}
    printf("\n************** Student Database **************\n");
    printf("Name\t ID\t Marks\n");
    while(read(fd,&s,sizeof(s))!='\0')
        printf("%s \t %d\t %d\n",s.sname,s.sid,s.marks);
    close(fd);
}

void search()
{
    student s;
    int x;
    int key;printf("Enter the sid of student");cini(key);
    int fd=open(filename,O_RDONLY,0666);
    if(fd==-1){printf("Error"); return;}
    while(x=read(fd,&s,sizeof(s))!='\0')
    {
        if(key==s.sid)
        {
            printf("Record Found");
            break;
        }  
    }
    if(x!=-1)
    printf("Name :: %s\nID :: %d\nMarks :: %d\n",s.sname,s.sid,s.marks);
    else
    printf("Record not found");
    close(fd);    
}

int main()
{   
    int ch,yn;
    do{
        printf("\n***************** Menu ***************\n");
        printf("\n1)Display Database");
        printf("\n2)Insert Record");
        printf("\n3)Search Record");
        printf("\n4)Exits");
        printf("\nEnter your Choice ::");cini(ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            search();
            break;
        case 4:
            printf("Want to delete the Database (1/0) :: ");cini(yn);
            if(yn) remove(filename);
            return 0;
        default:
            break;
        }
    }while(1);
    return 0;
}
