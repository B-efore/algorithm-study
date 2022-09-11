#include <stdio.h>
#include <stdlib.h>
#define N 1000
int dp[N + 1][N + 1];
int main(void)
{
	int i, j, len1, len2;
	char str1[N + 1], str2[N + 1];

	scanf("%s %s", str1, str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {

			if (str1[i] == str2[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else {

				if (dp[i][j+1] > dp[i+1][j])
					dp[i+1][j+1] = dp[i][j+1];
				else
					dp[i+1][j+1] = dp[i+1][j];
			}
		}
	}

	printf("%d\n", dp[len1][len2]);

	return 0;
}