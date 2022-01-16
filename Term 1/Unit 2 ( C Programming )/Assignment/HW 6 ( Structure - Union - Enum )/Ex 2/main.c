#include <stdio.h>
#include <stdlib.h>
struct Sdistance
{
    int feet;
    float inch;
};

struct Sdistance read_structure(char* str1)
{
    struct Sdistance d;
    printf("%s\n",str1);
    printf("enter feet: ");
    scanf("%d",&d.feet);
    printf("enter inch: ");
    scanf("%f",&d.inch);
    return d;
};

struct Sdistance add(struct Sdistance d1,struct Sdistance d2)
{
    struct Sdistance s;
    s.feet=d1.feet+d2.feet;
    s.inch=d1.inch+d2.inch;
    if(s.inch>12.05)
    {
        s.feet++;
        s.inch -=12.05;
    }
    return s;
};

int main()
{
    struct Sdistance d1,d2,sum;
    d1 = read_structure("enter 1st distance");
    d2 = read_structure("enter 2nd distance");
    sum = add(d1,d2);
    printf("sum of distances = %d' - %f",sum.feet,sum.inch);
    return 0;
}
