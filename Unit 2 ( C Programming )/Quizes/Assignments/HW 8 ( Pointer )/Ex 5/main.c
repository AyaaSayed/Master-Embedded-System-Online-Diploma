#include <stdio.h>
#include <stdlib.h>

struct Semployee
{
    char* name;
    int ID;
};

int main()
{
    static struct Semployee emp1 = {"aya",1},emp2 = {"israa",2},emp3 = {"alaa",3};
    struct Semployee (*arr[3]) = {&emp1,&emp2,&emp3};
    struct Semployee* ((*ptr)[3]) = &arr;
    for(int i=0;i<3;i++)
    {
        printf("Employee Name: %s\n",(*(*ptr+i))->name);
        printf("Employee ID: %d\n\n",(*(*ptr+i))->ID);
    }
    return 0;
}
