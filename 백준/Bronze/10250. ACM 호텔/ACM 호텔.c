#include <stdio.h>
int main(void)
{
	int t, h, w, n, index;
	scanf("%d", &t);

	for(int i=0; i<t; i++)
	{
		scanf("%d %d %d", &h, &w, &n);
		
		if (n%h!=0)
		{
			index = n%h*100;
			index += n/h +1;
		}
		else
		{
			index = h*100;
			index += n/h;
		}

		printf("%d\n", index);
	}
	return 0;
}
