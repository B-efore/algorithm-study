#include <stdio.h>
#include <math.h>
int Circle(int[]);
int main(void)
{
	int j, i, t;
	int point[6];
	scanf("%d", &t);

	for (j = 0; j < t; j++)
	{
		for (i = 0; i < 6; i++)
			scanf("%d", &point[i]);

		printf("%d\n", Circle(point));
	}

	return 0;
}
int Circle(int point[])
{
	double distance;
	int r, sub;

	r = point[2] + point[5];
	sub = (point[2] > point[5]) ? (point[2] - point[5]) : (point[5] - point[2]);
	distance = sqrt(pow(point[0] - point[3], 2) + pow(point[1] - point[4], 2));

	if (distance == 0 && point[2] == point[5])
		return -1;
	else if (r == distance || sub == distance)
		return 1;
	else if ((r > distance)&&(sub < distance))
		return 2;
	else
		return 0;
}