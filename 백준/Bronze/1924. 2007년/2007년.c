#include <stdio.h>
enum week
{
	SUN, MON, TUE, WED, THU, FRI, SAT
};
void PrintDay(int day){
	switch (day)
	{
		case SUN:
			printf("SUN\n");
			break;
		case MON:
			printf("MON\n");
			break;
		case TUE:
			printf("TUE\n");
			break;
		case WED:
			printf("WED\n");
			break;
		case THU:
			printf("THU\n");
			break;
		case FRI:
			printf("FRI\n");
			break;
		case SAT:
			printf("SAT\n");
	}
}
int main(void)
{
	int i, x, y, d;
	int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d %d", &x, &y);

	for(i=0; i<x; i++)
		y+=month[i];

	d=y%7;

	PrintDay(d);
	return 0;
}