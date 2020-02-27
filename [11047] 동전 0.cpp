// [11047] 동전 0
// https://www.acmicpc.net/problem/11047
// 그리디 알고리즘

#include <cstdio>
using namespace std;

int main(void)
{
	int n, k; // 준규가 가지고 있는 동전의 종류, 가치의 합
	int a[11]; // 동전의 가치
	scanf("%d %d", &n, &k);
	int remain = k, cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if ((remain / a[i]) >= 1) {
			cnt += remain / a[i];
			remain -= (remain / a[i])*a[i];
		}
		if (remain == 0)
			break;
	}
	printf("%d\n", cnt);
}