#include<stdio.h>

int m, n, answer;
int map[1000][1000];
void check(int a, int b);

int main() {
	int i, j;
	char c[1001] = { 0 };
	scanf("%d %d", &m, &n);

	for (i = 0; i < m; i++) {
		scanf("%s", c);
		for (j = 0; j < n; j++) {
			map[i][j] = c[j] - 48;
		}
	}
	for (i = 0; i < n; i++) {
		if (map[0][i] == 0)
			check(0, i);
	}

	printf("%s", answer ? "YES" : "NO");
}

void check(int a, int b) {

	map[a][b] = 1;

	if (a == m - 1) {
		answer = 1;
		return;
	} //끝까지 도착하면 true

	if (a < m - 1 && map[a + 1][b] == 0)
		check(a + 1, b); //아래
	if (b > 0 && map[a][b - 1] == 0)
		check(a, b - 1); //왼쪽
	if (b < n - 1 && map[a][b + 1] == 0)
		check(a, b + 1); //오른쪽
	if (a > 0 && map[a - 1][b] == 0)
		check(a - 1, b); //위
}