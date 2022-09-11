#include <cstdio>
#include <cstring>
#define N 1000
char S[N + 1];
char P[N + 1];
int main(void)
{
	scanf("%s", S);
	scanf("%s", P);

	int cnt = 0;
	int len1 = strlen(S);
	int len2 = strlen(P);

	for (int i = 0; i < len2;) {

		int max = 0;

		for (int j = 0; j < len1; j++) {

			int tmp = 0;

			while (S[j+tmp] == P[i+tmp]) tmp++;
			if (max < tmp) max = tmp;
		}

		i += max;
		cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}