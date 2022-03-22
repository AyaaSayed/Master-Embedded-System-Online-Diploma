int num, n;
    int i, lastDigit;
    int freq[BASE]={0};
    printf("Enter any number: ");
    scanf("%d", &num);
    n = num;
    while(n != 0)
    {
        lastDigit = n % 10;
        n /= 10;

        freq[lastDigit]=freq[lastDigit]+1;
    }
    printf("Frequency of each digit in %d is: \n", num);
    for(i=0; i<BASE; i++)
    {
        if(freq[i]!=0)
        printf("Frequency of %d = %d\n", i, freq[i]);
    }
    return 0;
}

