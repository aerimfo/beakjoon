// [1654] 랜선 자르기
// https://www.acmicpc.net/problem/1654
// 이분 탐색
/* 랜선이 10,000개이고 모두 1cm로 자르면 10,000x(2^31-1) 조각이 나옴
  -> left, right, mid, answer 모두 long long 타입으로 선언!! */ 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int> &lan, int k, int n);
int make(vector<int> &lan, int k, int length);

int main(void)
{
	int k, n; // 오영식이 이미 가지고 있는 랜선의 개수, 필요한 랜선의 개수
	scanf("%d %d", &k, &n);
	vector<int> lan(k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &lan[i]);
	}
	sort(lan.begin(), lan.end());
	printf("%d\n", check(lan, k, n));
}

int check(vector<int> &lan, int k, int n)
{
	long long left = 1;
	long long right = lan[k - 1];
	long long answer = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (make(lan, k, mid) >= n) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}

int make(vector<int> &lan, int k, int length)
{
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += lan[i] / length;
	}
	return cnt;
}