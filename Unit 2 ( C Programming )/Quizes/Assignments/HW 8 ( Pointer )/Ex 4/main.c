#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[15],*ptr,i,num;
    printf("input the number of elements to store in the array(max 15): \n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("the elements of array in reverse order are: \n");
    for(i=num-1;i>=0;i--)
    {
        ptr=arr+i;
        printf("element %d: %d\n",i+1,*ptr);
    }
    return 0;
}
