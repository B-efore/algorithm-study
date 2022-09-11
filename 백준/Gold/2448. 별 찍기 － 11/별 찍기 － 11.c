#include <stdio.h>
#define Y 3072
#define X 6144
char star[Y+1][X+1];
void Divide(int, int, int);
int main(void){
    
    int n;
    
    scanf("%d", &n);
    Divide(n, n, 1);
    
    for(int y=1; y<=n; y++){
        for(int x=1; x<2*n; x++){
            if(star[y][x]=='*')
                printf("%c", star[y][x]);
            else
                printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
void Divide(int n, int x, int y){
    
    if (n==3){
        star[y][x] = '*';
        star[y+1][x-1] = '*';
        star[y+1][x+1] = '*';
        for(int i=0; i<5; i++)
            star[y+2][2+x-i] = '*';
        
        return;
    }
    
    Divide(n/2, x, y);
    Divide(n/2, x-(n/2), y+(n/2));
    Divide(n/2, x+(n/2), y+(n/2));
    
    return;
}