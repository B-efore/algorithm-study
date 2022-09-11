#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define N 1003001
bool p[N+1];
void setPrime();
bool check(int);
int main(void)
{
        memset(p, true, sizeof(p));
        setPrime();

        int n;
        scanf("%d", &n);

        for(int i=n; i<=N; i++){
                if(p[i]){
                        if(check(i)){
                                printf("%d\n", i);
                                break;
                        }
                }
        }

        return 0;
}
void setPrime()
{
        p[0] = false; p[1] = false;

        for(int i=2; i<=sqrt(N); i++){
                for(int j=i*2; j<=N; j+=i){
                        if(p[i])
                                p[j] = false;
                }
        }
}
bool check(int num)
{
        char str1[10];
        char str2[10];

        int tmp = num;
        int i = 1, j = 1, len;
        bool c = true;

        while(tmp>0){
                str2[i] = tmp%10;
                tmp/=10; i++;
        }

        i--;
        len = i;

        while(i>0){
                str1[j] = str2[i];
                j++; i--;
        }

        for(i=1; i<=len; i++){
                        if(str1[i]!=str2[i]){
                                c = false;
                                break;
                        }
        }

        return c;
}