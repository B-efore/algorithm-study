#include <stdio.h>
int main(void)
{
    int n, i, max=0;
    double avg, sum=0.0;
    scanf("%d", &n);
    
    int grade[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &grade[i]);
        if (grade[i]>max)
            max = grade[i];
    }
    
    for(i=0; i<n; i++)
        sum+=(double)grade[i]/max*100;
    
    avg = (double)sum / n;
    printf("%.2f\n", avg);
    
    return 0;
}