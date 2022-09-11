#include <stdio.h>
int main(void)
{
    int arr[9];
    int i, max, n=1;
    
    for(i=0; i<9; i++)
        scanf("%d", &arr[i]);
    
    max = arr[0];
    
    for(i=1; i<9; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            n = i+1;
        }
    }
    
    printf("%d\n", max);
    printf("%d\n", n);
    
    return 0;
}