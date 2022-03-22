
void draw_circle(int radius)
{
     int i,j;
    for (i=0; i<=2*radius; i++)
    {
        for (j=0; j<=2*radius; j++)
        {
            double distance = sqrt((double)(i-radius)*(i-radius) + (j-radius)*(j-radius));
            if (distance>radius-0.5 && distance<radius+0.5)
            {
                printf("*");
            }
            else
            {
                 printf(" ");
                 }
        }
        printf("\n");
    }
}
int main()
{
    int radius ;
    printf("enter radious:");
    scanf("%d",&radius);
   draw_circle(radius);
    return 0;
}
