#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int abs2(int a, int b) {
    return (a - b > 0 ? a - b : b - a);
}

char* solution(int n, int m, int x, int y, int r, int c, int k) {

    char* answer = (char*)malloc(k + 1);
    // 상, 하 이동
    int vMove = r - x;
    // 좌, 우 이동
    int hMove = c - y;
    // 전체 이동 (최소)
    int mMove = abs2(r, x) + abs2(c, y);
    // 남은 이동 거리
    int rMove = abs2(k, mMove);

    if (rMove % 2 == 1 || mMove > k) {
        strcpy(answer, "impossible");
    }
    else {

        int i = 0, h = 0, v = 0, nx = x, ny = y;

        // 1. d (최단 경로)
        while (vMove > 0) {
            answer[i++] = 'd';
            vMove--; nx++;
        }
        // 1. d (남은 거리)
        if (nx < n && rMove > 0) {
            for (int l = rMove; nx<n && l>rMove / 2; l--) {
                answer[i++] = 'd';
                h++; nx++;
            }
            rMove -= (2 * h);
        }
        // 2. l (최단 경로)
        while (hMove < 0) {
            answer[i++] = 'l';
            hMove++; ny--;
        }
        // 2. l (남은 거리)
        if (ny > 1 && rMove > 0) {
            for (int l = rMove; ny > 1 && l > rMove / 2; l--) {
                answer[i++] = 'l';
                v++; ny--;
            }
            rMove -= (2 * v);
        }
        // 3. r (남은 거리)
        while (ny < m && rMove>0) {
            answer[i++] = 'r';
            answer[i++] = 'l';
            rMove -= 2;
        }
        while (v > 0) {
            answer[i++] = 'r';
            v--;
        }
        // 3. r (최단 경로)
        while (hMove > 0) {
            answer[i++] = 'r';
            hMove--;
        }
        // 4. u (최단 경로)
        while (vMove < 0) {
            answer[i++] = 'u';
            vMove++;
        }
        // 4. u (남은 거리)
        while (h > 0) {
            answer[i++] = 'u';
            h--;
        }

        answer[i] = '\0';
    }

    return answer;
}

int main(void) {

    int n, m, x, y, r, c, k;
    scanf("%d %d %d %d %d %d %d", &n, &m, &x, &y, &r, &c, &k);

    printf("%s\n", solution(n, m, x, y, r, c, k));
    return 0;
}