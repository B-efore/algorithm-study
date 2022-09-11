#include <stdio.h>
int main(void)
{
	int i, l, p, people;
	int num[5];
	scanf("%d %d", &l, &p);
	
	people = l*p;

	for(i=0; i<5; i++)
		scanf("%d", &num[i]);

	for(i=0; i<5; i++)
		printf("%d ", num[i]-people);

	return 0;
}	