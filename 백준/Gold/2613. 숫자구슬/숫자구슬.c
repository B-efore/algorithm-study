#include <stdio.h>
#define N 300

int n, m;
int number[N];

void parametric(int, int);
int condition(int);
int main(void){

	int tmp=0, sum=0;

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++){
		scanf("%d", &number[i]);
		sum += number[i];

		if(tmp<number[i])
			tmp = number[i];
	}

	if(m==1){
		printf("%d\n", sum);
		printf("%d\n", n);
	}
	else if(m==n){
		printf("%d\n", tmp);
		
		for(int i=0; i<n; i++)
			printf("1 ");
		printf("\n");
	}
	else
		parametric(tmp, sum);
	
	return 0;
}
void parametric(int min, int max){
	
	int k;

	while(1){

		k = (min + max) / 2;

		if(min == max){
			printf("%d\n", k);
			
			int tmp=0, num=0;

			for(int i=0; i<n; i++){

				if(tmp+number[i] <= k){
					tmp += number[i];
					num++;
				}
				else{
					printf("%d ", num);
					m--;
					tmp = number[i];
					num = 1;
				}

				if(i==n-1){
					printf("%d\n", num);
					m--;
				}

				if(n-i==m){
					while(m--){
						printf("%d ", num);
						num=1;
					}

					printf("\n");
					break;
				}
			}
			break;
		}

		if(condition(k) <= m)
			max = k;
		else
			min = k+1;
	}
}
int condition(int k){
	
	int tmp=0, groupNum=1;

	for(int i=0; i<n; i++){
		if(tmp+number[i] <= k){
			tmp += number[i];
		}
		else{
			tmp = number[i];
			groupNum++;
		}
	}

	return groupNum;
}