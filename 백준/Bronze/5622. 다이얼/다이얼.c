#include <stdio.h>
int main(void)
{
	char a;
	int i=0, num=0;

	while((a=getchar())!='\n')
	{
		if (a=='A'||a=='B'||a=='C')
			num+=3;
		else if (a=='D'||a=='E'||a=='F')
			num+=4;
		else if (a=='G'||a=='H'||a=='I')
			num+=5;
		else if (a=='J'||a=='K'||a=='L')
			num+=6;
		else if (a=='M'||a=='N'||a=='O')
			num+=7;
		else if (a=='P'||a=='Q'||a=='R'||a=='S')
			num+=8;
		else if (a=='T'||a=='U'||a=='V')
			num+=9;
		else if (a=='W'||a=='X'||a=='Y'||a=='Z')
			num+=10;
		i++;
	}

	printf("%d\n", num);
	return 0;
}