#include <stdio.h>
void hansu(int n)
{
    char check;
    int i, k, j, su=0;
    int num[4];
    
    for (i=1; i<=n; i++)
    {
        check='O';
        k=i;
		j=0;
        
        while (k>0)
        {
            num[j]=k%10;
            k=k/10;
            j++;
        }
        
		if (j<3)
			;
		else
		{
      	  for (k=0; k<j-2; k++)
        	{
    	        if ((num[k]-num[k+1])!=(num[k+1]-num[k+2]))
	            {
            	    check='X';
        	        break;
    	        }
	        }
		}
        
        if (check=='O')
            su++;
    }
    printf("%d\n", su);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    hansu(n);
    return 0;
}