#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 1000000

typedef struct {
	int index;
	int data;
	struct NODE * next;
} NODE;

NODE *head = NULL;
NODE *tail = NULL;
NODE *cursor = NULL;
int nIndex = 0;

void setPrimeNumber(bool p[]);
void add(int data);
int main(void){

	int i, j, n, num;

	//에라토스테네스의 체, 소수 구하기
	bool p[N];
	
	memset(p, 1, (N+1)*sizeof(bool));
	setPrimeNumber(p);

	//소수 저장
	head = (NODE *)malloc(sizeof(NODE));
	tail = head;

	for(i=2; i<=N; i++)
		if(p[i])
			add(i);

	//입력
	scanf("%d", &n);

	//소인수분해 저장 공간 할당
	int ** number = (int **)calloc((n+1), sizeof(int*));
	for(i=0; i<n+1; i++)
		number[i] = (int *)calloc(nIndex, sizeof(int));

	int max=0;

	for(i=0; i<n; i++){
		scanf("%d", &num);

		if(max<num)
			max = num;

		cursor = head->next;
	
		//소인수분해
		while(cursor->data <= num){
			while(num % (cursor->data) == 0){
				num /= (cursor->data);
				number[i][cursor->index]++;
			}

			cursor = cursor -> next;
		}
	}

	//인수 합 구하기
	for(i=0; i<nIndex; i++)
		for(j=0; j<n; j++)
			if(number[j][i] > 0)
				number[n][i] += number[j][i];

	//최종 풀이
	int tmp, sumNumber=0;
	long long sum=1;

	cursor = head->next;

	while(cursor->data <= max){

		tmp = number[n][cursor->index]/n;

		if(tmp>0){
			sum *= pow(cursor->data, tmp);

			for(i=0; i<n; i++)
				if(number[i][cursor->index] < tmp)
					sumNumber += tmp - number[i][cursor->index];
		}

		cursor = cursor -> next;
	}

	printf("%lld %d\n", sum, sumNumber);
	return 0;
}
void setPrimeNumber(bool p[]){
	for(int i=2; i<= sqrt(N); i++){
		if(p[i]){
			for(int j=i*2; j<=N; j+=i)
				p[j] = false;
		}
	}
}
void add(int data){

	NODE *newNode = (NODE *)malloc(sizeof(NODE));

	newNode -> data = data;
	newNode -> next = NULL;
	newNode -> index = nIndex++;

	tail -> next = newNode;
	tail = newNode;
}