#include <stdio.h>
int main(void)
{
    char check[10];
    int n[10], re[10];
    int i, k, num=10;
    
    for(i=0; i<10; i++)
    {
		check[i]='X';
        scanf("%d", &n[i]);
        re[i]=n[i]%42;
    }
    
    for(i=0; i<10; i++){
        for(k=i+1; k<10; k++){
			if(check[i]=='O')
				break;
            if(re[k]==re[i]){
                check[k]='O';
				num--;
            }
        }
    }
    
    printf("%d\n", num);
    return 0;
}