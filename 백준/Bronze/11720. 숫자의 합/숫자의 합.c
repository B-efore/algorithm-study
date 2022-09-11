#include <stdio.h>
#define N 100
int main(void)
{
    int n, i, sum=0;
    char num[N];
	
	scanf("%d", &n);
    scanf("%s", num);
    
	for(i=0; i<n; i++)
        sum+=num[i]-48;
    
	printf("%d\n", sum);
    return 0;
}