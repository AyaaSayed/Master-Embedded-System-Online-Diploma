#include <stdio.h>
#include <stdlib.h>

float square(int num)
{
    int start=0,end=num,mid,i;
    float ans,increment =0.1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(mid*mid==num)
        {
            ans=mid;
            break;
        }
        if(mid*mid<num)
        {
            start=mid+1;
            ans=mid;
        }
        else
            end=mid-1;
    }

    for (i=0;i<5;i++)
    {
        while (ans*ans<=num)
        {
            ans+=increment;
        }
        ans=ans-increment;
        increment=increment/10;
    }
    return ans;
}

int main()
{
    int num;  float ans;
    printf("enter number: ");
    scanf("%d",&num);
    ans=square(num);
    printf("%f",ans);
    return 0;
}
