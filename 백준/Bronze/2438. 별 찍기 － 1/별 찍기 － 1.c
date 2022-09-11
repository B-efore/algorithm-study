#include <stdio.h>
int main(void)
{
    int n, i, k;
    scanf("%d", &n);
    
    for(i=1; i<=n; i++){
        for(k=0; k<i; k++)
            printf("*");
        printf("\n");
    }
    return 0;
}