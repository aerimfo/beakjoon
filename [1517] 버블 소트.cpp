// [1517] 버블 소트
// https://www.acmicpc.net/problem/1517
// 정렬

#include <cstdio>
#define MAX 500001
using namespace std;

long long solve(int start, int end);
int a[MAX], answer[MAX];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%ld\n", solve(0, n - 1));
}

long long solve(int start, int end)
{
	if (start == end) {
		return 0;
	}
	int mid = (start + end) / 2;
	long long cnt = solve(start, mid) + solve(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || a[i] <= a[j])) {
			answer[k++] = a[i++];
		}
		else {
			// (mid - i) = 왼쪽 리스트에 남아있는 숫자의 개수
			cnt += (long long)(mid - i + 1);
			answer[k++] = a[j++];
		}
	}
	for (int i = start; i <= end; i++) {
		a[i] = answer[i - start];
	}
	return cnt;
}