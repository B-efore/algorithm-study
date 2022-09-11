#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10000

typedef struct node {
	short x;
	short y;
	char visit;
	int left;
	int right;
} Node;

Node tree[N+1];
short point[2][N+1];
short xPoint;

void inorderTraversal(int number, short yPoint);
int main(void){

	int i, n, num, leftNum, rightNum;
	int root = -1;

	//입력
	scanf("%d", &n);

	for(i=0; i<n; i++){

		scanf("%d %d %d", &num, &leftNum, &rightNum);

		tree[num].visit++;
		tree[leftNum].visit++;
		tree[rightNum].visit++;

		//왼쪽 자식 연결
		if(leftNum!=-1)
			tree[num].left = leftNum;

		//오른쪽 자식 연결
		if(rightNum!=-1)
			tree[num].right = rightNum;
	}

	//루트 업데이트
	for(i=1; i<N; i++)
		if(tree[i].visit==1)
			root = i;

	//좌표 정렬
	inorderTraversal(root,1);

	short tmp, max=0, maxNumber=0;
	i=1;

	//최대 너비 구하기
	while(!((point[0][i]==0)||(point[1][i]==0)))
	{
		tmp = point[1][i] - point[0][i] + 1;

		if(tmp > max)
		{
			max = tmp;
			maxNumber = i;
		}

		i++;
	}

	printf("%d %d\n", maxNumber, max);
	return 0;
}
void inorderTraversal(int number, short yPoint){

	if(number==0)
		return;

	inorderTraversal(tree[number].left, yPoint+1);

	xPoint++;
	tree[number].x = xPoint;
	tree[number].y = yPoint;

	if(point[0][yPoint]==0 || point[0][yPoint]>xPoint)
		point[0][yPoint] = xPoint;
	
	if(point[1][yPoint]==0 || point[1][yPoint]<xPoint)
		point[1][yPoint] = xPoint;

	inorderTraversal(tree[number].right, yPoint+1);
}