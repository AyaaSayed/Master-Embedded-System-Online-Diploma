int main()
{
   int num, n,revers=0,digits;
    printf("Enter any number: ");
    scanf("%d", &num);
    n = num;
    //no of digits-1
    digits=(int)log10(n);
    while(n != 0)
    {
        revers=10*revers+(n%10);
        n=n/10;

    }
    //no of zeros
    digits=digits-((int)log10(revers));

    while(revers!=0)
    {
        switch(revers%10)
        {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
        revers=revers/10;
    }
   while(digits)
   {
       printf("zero ");
       digits--;
   }
    return 0;
}
