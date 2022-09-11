#include <stdio.h>
#define N 10000
int money[N+1];
void solve(int, int);
int check(int, int);
int main(void)
{
        int i, n, m;
        scanf("%d", &n);

        for(i=1; i<=n; i++)
                scanf("%d", &money[i]);

        scanf("%d", &m);

        solve(m, n);
        return 0;
}
void solve(int m, int n)
{
        int start, end, mid;
        start = 1;
        end = m;

        int sum, max=0, maxMoney=0, tmp;

        while(start<=end){

                mid = (start+end)/2;

                if((sum=check(mid, n))>m)
                        end = mid - 1;
                else
                        start = mid + 1;

                if(sum<=m && max<sum){
                        max = sum;
                        maxMoney = mid;
                }
        }

        max = 0;

        for(int i=1; i<=n; i++){
                if(money[i]<=maxMoney)
                        tmp = money[i];
                else
                        tmp = maxMoney;

                if(tmp>max)
                        max = tmp;
        }

        printf("%d\n", max);
}
int check(int num, int n)
{
        int sum=0;

        for(int i=1; i<=n; i++){
                if(money[i]<=num){
                        sum += money[i];
                }
                else{
                        sum += num;
                }
        }

        return sum;
}