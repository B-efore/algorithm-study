#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, k, n, c;
    double sum1, sum2, avg1, avg2;
    int * grade;
    int * tmp;
    
    scanf("%d", &c);
    
    for(i=0; i<c; i++)
    {
        sum1 = 0.0;
        sum2 = 0.0;
        scanf("%d", &n);
        grade = (int *)malloc(sizeof(int)*n);
        
        for(k=0; k<n; k++)
        {
            scanf("%d", &grade[k]);
            sum1+=(double)grade[k];
        }
        
        avg1 = sum1/n;
        
        for(k=0; k<n; k++)
            if ((double)grade[k]>avg1)
                sum2++;
        
        avg2 = (sum2/n)*100;
        printf("%.3f%\n", avg2);

		tmp = grade;
		free(tmp);
    }
    return 0;
}