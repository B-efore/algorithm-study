#include <stdio.h>
#include <stdlib.h>
void mix(int (**arr), int n, int m);
int main(void)
{
	int i, j, n, m, r;
	int** arr;
	scanf("%d %d %d", &n, &m, &r);

	//배열 동적 할당!
	arr = (int**)malloc(sizeof(int*)*n);
	for(i=0; i<n; i++)
		arr[i] = (int *)malloc(sizeof(int)*m);

	//배열 값 넣기
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &arr[i][j]);

	//배열 회전
	for(i=0; i<r; i++)
		mix(arr, n, m);

	//회전 결과 출력
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
void mix(int (**arr), int n, int m)
{
	int i, tmp1, tmp2;
	int up=0, down=n-1, right=m-1, left=0;

	while((left<right)&&(up<down))
	{
		// 왼쪽 밀기
		tmp1 = arr[down][left];
		for(i=down; i>up; i--)
			arr[i][left]=arr[i-1][left];
		left++;

		// 아래 밀기
		tmp2 = arr[down][right];
		for(i=right; i>left; i--)
			arr[down][i]=arr[down][i-1];
		arr[down][left] = tmp1;
		down--;

		// 오른쪽 밀기
		tmp1 = arr[up][right];
		for(i=up; i<down; i++)
			arr[i][right] = arr[i+1][right];
		arr[down][right] = tmp2;
		right--;

		// 위쪽 밀기
		for(i=left; i<=right; i++)
			arr[up][i-1] = arr[up][i];
		arr[up][right] = tmp1;
		up++;
	}
}