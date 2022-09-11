#include <stdio.h>
int main(void)
{
    int n[3], num[10] = {0};
	int i, sum;
    
	//숫자 3개 받기
    for(i=0; i<3; i++)
        scanf("%d", &n[i]);
    
    sum = n[0] * n[1] * n[2];

	//숫자 세기
    while(1)
    {
        i=sum%10;
        num[i]++;
        sum=sum/10;
        if (sum<1)
            break;
    }
    for(i=0; i<10; i++)
        printf("%d\n", num[i]);
    return 0;
}