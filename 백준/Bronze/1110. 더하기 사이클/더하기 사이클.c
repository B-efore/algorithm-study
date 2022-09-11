#include <stdio.h>
int main(void)
{
    int n, rn, ln, tmp, num=0;
    
    scanf("%d", &n);
    tmp = n;
    
    while(1){
        ln = n%10;
        rn = (n%10 + n/10)%10;
        n = ln*10 + rn;
        num ++;
        if (n==tmp)
            break;
    }
    printf("%d\n", num);
    return 0;
}