// [2805] 나무 자르기
// https://www.acmicpc.net/problem/2805
// 이분 탐색

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long check(vector<long long> &tree, int n, long long m);
long long cut(vector<long long> &tree, int n, long long height);

int main(void)
{
	int n; // 나무의 수
	long long m; // 상근이가 집으로 가져가려고 하는 나무의 길이
	scanf("%d %lld", &n, &m);
	vector<long long> tree(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
	}
	sort(tree.begin(), tree.end());
	printf("%d\n", check(tree, n, m));
}

long long check(vector<long long> &tree, int n, long long m)
{
	long long left = 0;
	long long right = tree[n - 1];
	long long answer = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (cut(tree, n, mid) >= m) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}

long long cut(vector<long long> &tree, int n, long long height)
{
	long long length = 0;
	for (int i = 0; i < n; i++) {
		// 자르고자 하는 높이보다 나무가 긴 경우 -> 자를 수 있음
		if (tree[i] > height)
			length += tree[i] - height;

		// 나무가 짧아서 자를 수 없는 경우
		else
			;
	}
	return length;
}