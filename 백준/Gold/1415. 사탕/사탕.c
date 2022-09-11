#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define N 50
#define MAX 10000

bool prime[MAX*N+1];
long long price[MAX*N+1];
int count[MAX+1];
int candy[N];

void setPrimeNumber(bool *);

int main(void){

	long long result;
	int i, j, k, n, tmp, zero=1;
	scanf("%d", &n);

	for(i=0; i<MAX*N+1; i++)
		prime[i] = true;

	setPrimeNumber(prime);

	for(i=0; i<n; i++){

		scanf("%d", &candy[i]);
		count[candy[i]]++;
	}

	price[0] = 1;

	for(i=0; i<n; i++){

		tmp = candy[i];

		if(tmp==0){
			zero++;
			continue;
		}

		for(j=MAX*N; j>=0; j--){
			for(k=1; k<=count[tmp]; k++){


				if(j+k*tmp<MAX*N+1){
						price[j+k*tmp]+=price[j];
				}
				else
					break;
			}
		}

		count[tmp] = 0;
	}

	result=0;

	for(i=2; i<MAX*N; i++)
		if(prime[i])
			result += price[i];

	printf("%lld\n", result*zero);
	return 0;
}
void setPrimeNumber(bool prime[]){

	for(int i=2; i<=sqrt(MAX*N); i++){
		if(prime[i]){
			for(int j=i*2; j<=MAX*N; j+=i)
				prime[j] = false;
		}
	}
}