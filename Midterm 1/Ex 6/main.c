#include <stdio.h>
#include <stdlib.h>

int fun(int arr[],int size)
{
    int *p=arr,i,j,c=0,counter=0,array[7];
    for(j=0;j<size;j++,p++)
    {
        counter=0;
        for(i=0;i<size;i++)
        {
            if(*p==arr[i])
            counter++;
        }
        if(counter==1)
        {
            array[c]=*p;
            c++;
        }
    }printf("the unique number is: ");
    for(i=0;i<c;i++)
    {
        printf("%d ",array[i]);
    }
}

int main()
{
    int num,size,arr[]={4,2,5,2,5,7,4};
    size=sizeof(arr)/sizeof(arr[0]);
    num=fun(arr,size);
    return 0;
}
