#include <stdio.h>
int main(void)
{
	int i, sum=0;
	int arr[5];
	
	for(i=0; i<5; i++)
		scanf("%d", &arr[i]);

	for(i=0; i<5; i++)
		sum+=arr[i]*arr[i];

	printf("%d\n", sum%10);
	return 0;
}