#include <stdio.h>
int main(void)
{
    int h, m;
    scanf("%d %d", &h, &m);
    
    if (m<45)
    {
        if (h<1)
            h=h+24-1;
        else
            h=h-1;
        
        m=m+60-45;
        printf("%d %d\n", h, m);
    }
    else
        printf("%d %d\n", h, m-45);
    
    return 0;
}