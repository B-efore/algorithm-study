#include <cstdio>
#define N 50
#define A 26
char name[N + 1];
int alphabet[A + 1];

bool check(int length, int odd_number);
int main(void)
{
	int i, c, len = 0, odd_idx, odd_number = 0;

	while ((c = getchar()) != '\n') {
		alphabet[c - 'A']++;
		len++;
	}

	for (c = 0; c < A; c++) {
		if (alphabet[c] % 2 == 1) {
			name[len/2] = 'A' + c;
			alphabet[c]--;
			odd_number++;
		}
	}

	if (check(len, odd_number)) {
		for (i=0, c = 0; c < A; c++) {
			while(alphabet[c]>1) {
				name[i++] = 'A' + c;
				name[--len] = 'A' + c;
				alphabet[c] -= 2;
			}
		}

		printf("%s\n", name);
	}
	else
		printf("I'm Sorry Hansoo\n");

	return 0;
}

bool check(int length, int odd_number) {

	if (length % 2 == 0 && odd_number == 0) return true;
	if (length % 2 == 1 && odd_number == 1) return true;
	return false;
}