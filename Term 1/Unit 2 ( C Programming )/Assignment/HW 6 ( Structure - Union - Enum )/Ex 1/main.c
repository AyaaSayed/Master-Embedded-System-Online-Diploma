#include <stdio.h>
#include <stdlib.h>
struct Sstudent
{
    char name[20];
    int roll;
    float mark;

};

void print(struct Sstudent s,char* str2)
{
    printf("%s\n",str2);
    printf("name: ");
    puts(s.name);
    printf("roll number: %d\n",s.roll);
    printf("mark: %f\n",s.mark);
}

struct Sstudent read_structure(char* str1)
{
    printf("%s\n",str1);
    struct Sstudent s;
    printf("enter name: ");
    gets(s.name);
    printf("enter roll number: ");
    scanf("%d",&s.roll);
    printf("enter his mark: ");
    scanf("%f",&s.mark);
    return s;
};

int main()
{
    struct Sstudent s;
    s=read_structure("enter information of students");
    print(s,"displaying information");
    return 0;
}
