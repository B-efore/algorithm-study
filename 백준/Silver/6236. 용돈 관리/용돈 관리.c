#include <stdio.h>
#define N 100000
int n, m;
int money[N];
void parametric(int, int);
int condition(int);
int main(void){
	
	int i, max=0, sum=0;

	scanf("%d %d", &n, &m);

	for(i=0; i<n; i++){
		scanf("%d", &money[i]);
		sum += money[i];

		if(money[i]>max)
			max = money[i];
	}

	if(m==1){
		printf("%d\n", sum);
	}
	else if(m==n){
		printf("%d\n", max);
	}
	else{
		parametric(max, sum);
	}
	
	return 0;
}
void parametric(int min, int max){

	int k = (min+max)/2;

	if(min==max){
		printf("%d\n", k);
		return;
	}

	if(condition(k) <= m){
		parametric(min, k);
	}
	else{
		parametric(k+1, max);
	}
}
int condition(int k){
	
	int myMoney=0, result=0;

	for(int i=0; i<n; i++){
		if(money[i] > myMoney){
			myMoney = 0;
			myMoney += k;
			result++;
		}
		myMoney -= money[i];
	}

	return result;
}