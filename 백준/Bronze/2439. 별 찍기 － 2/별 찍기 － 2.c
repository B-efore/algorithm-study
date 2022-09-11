#include <stdio.h>
int main(void)
{
    int n, i, k, j;
    scanf("%d", &n);
    
    for(i=1; i<=n; i++)
    {
        for(k=n-i; k>0; k--)
            printf(" ");
        for(j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}