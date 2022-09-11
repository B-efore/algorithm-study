#include <stdio.h>
int main(void)
{
	int x, y, w, h, tmp;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	tmp = x;

	if (w - x < tmp)
		tmp = w - x;

	if (h - y < tmp)
		tmp = h - y;

	if (y < tmp)
		tmp = y;

	printf("%d\n", tmp);
	return 0;
}