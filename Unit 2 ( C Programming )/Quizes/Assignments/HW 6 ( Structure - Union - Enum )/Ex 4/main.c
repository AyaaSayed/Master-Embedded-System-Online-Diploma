#include <stdio.h>
#include <stdlib.h>
struct Sstudent
{
    char name[20];
    int roll;
    float mark;

};

void print(struct Sstudent s)
{
    printf("name: ");
    puts(s.name);
    printf("roll number: %d\n",s.roll);
    printf("mark: %f\n",s.mark);
}

struct Sstudent read_structure()
{
    struct Sstudent s;
    printf("enter name: ");
    /*****************************************/
    fflush(stdin); gets(s.name);fflush(stdout);
    /*****************************************/
    printf("enter roll number: ");
    scanf("%d",&s.roll);
    printf("enter his mark: ");
    scanf("%f",&s.mark);
    return s;
};

int main()
{
    struct Sstudent S[10];
    int i;
    printf("enter information of students\n");
    for(i=0;i<10;i++)
    {
        S[i]=read_structure();
        printf("\n");
    }
    printf("displaying information\n");
    for(i=0;i<10;i++)
    {
        print(S[i]);
        printf("\n");
    }
    return 0;
}
