#include <stdio.h>
int main(void)
{
    int num[5000]={0};
    int n, k, index, check=0;
    scanf("%d %d", &n, &k);
    
    index = k;
    
    printf("<");
    for(int i=0; i<n; i++)
    {
        if (i==n-1)
            printf("%d", index);
        else
            printf("%d, ", index);
        
		num[index]=1;
		check++;
        
        for(int j=0; j<k;)
        {
            index++;
            
            if(check==n)
                break;
            if(index>n)
                index=1;
            if(num[index]!=1)
                j++;
        }
    }
    printf(">\n");
    return 0;
}