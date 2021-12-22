#include <stdio.h>
#include <stdlib.h>

int print_array(int arr1[],int arr2[],int i,int j)
{
    int n;
    printf("enter 1st array after swapping: ");
    for(n=0;n<j;n++)
    {
        printf("%d ",arr1[n]);
    }
    printf("\nenter 2nd array after swapping: ");
    for(n=0;n<i;n++)
    {
        printf("%d ",arr2[n]);
    }
}

int swap(int arr1[],int arr2[],int i,int j)
{
    int temp[20],n;
    for(n=0;n<j;n++)
    {
        temp[n]=arr1[n];
        arr1[n]=arr2[n];
        arr2[n]=temp[n];
    }
    for(n=i-j;n<i;n++)
    {
        arr2[n]=arr1[n];
    }
    print_array(arr1,arr2,i,j);
}

int main()
{
    int arr1[20],s1,arr2[20],s2,i;
    printf("enter array1 size: ");
    scanf("%d",&s1);
    printf("enter 1st array: \n");
    for(i=0;i<s1;i++)
    {
        printf(" ");
        scanf("%d",&arr1[i]);
    }
    printf("enter array2 size: ");
    scanf("%d",&s2);
    printf("enter 1st array: \n");
    for(i=0;i<s2;i++)
    {
        printf(" ");
        scanf("%d",&arr2[i]);
    }

    if(s1>=s2)
        swap(arr1,arr2,s1,s2);
    else
        swap(arr1,arr2,s2,s1);

    return 0;
}
