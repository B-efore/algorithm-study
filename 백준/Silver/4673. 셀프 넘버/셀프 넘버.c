#include <stdio.h>
void d()
{
    int k, n, i, sum;
    char check;
    
    for(i=1; i<=10000; i++)
    {
        for(k=1; k<=i; k++)
        {
			sum = 0;
			check = 'X';
			n=k;

            sum+=n;
            while (n>0)
			{
                sum+=n%10;
                n=n/10;
            }

            if(sum==i)
			{
                check = 'O';
				break;
			}
        }
        
        if (check=='X')
            printf("%d\n", i);
    }
}
int main(void)
{
	d();
	return 0;
}