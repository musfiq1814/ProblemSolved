#include<stdio.h>
int main()
{
    int i,sum=0,n;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        sum += i;
    }

    printf("%d\n", sum);
    printf("this is last line");
    return 0;
}