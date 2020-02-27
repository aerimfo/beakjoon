// [2110] 공유기 설치
// https://www.acmicpc.net/problem/2110
// 이분 탐색(Binary Search)

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int> &x, int n, int c);
int router(vector<int> &x, int n, int mid);

int main(void)
{
	int n, c; // 집의 개수, 공유기의 개수
	scanf("%d %d", &n, &c);
	vector<int> x(n);

	// 집의 좌표
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x.begin(), x.end());
	printf("%d\n", check(x, n, c));
}

int check(vector<int> &x, int n, int c)
{
	int left = 1; // 집 좌표의 시작 : 1
	int right = x[n-1]; // 첫 번째, 마지막 집 사이의 거리
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (router(x, n, mid) >= c) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}

int router(vector<int> &x, int n, int mid)
{
	int cnt = 1, tmp = 0;
	for (int i = tmp + 1; i < n; i++) {
		if ((x[i] - x[tmp]) >= mid) {
			cnt++;
			tmp = i;
		}
	}
	return cnt;
}