#include <stdio.h>
#define N 80
int main(void)
{
    int n, i, j, tmp=1, sum;
    char OX[N];
    
	scanf("%d", &n);

    for(i=0; i<n; i++){
        sum=0; j=0;
		scanf("%s", OX);

        while(OX[j]!='\0'){
            if (OX[j]=='O')
            {
                if (j==0)
                    tmp=1;
                else if (OX[j-1]=='O')
                    tmp++;
            
                sum+=tmp;
            }
            else
                tmp=1;
			j++;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}