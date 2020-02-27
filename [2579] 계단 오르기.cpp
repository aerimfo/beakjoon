// [2579] 계단 오르기
// https://www.acmicpc.net/problem/2579
// dp

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int stairs[301], dp[301];
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}

	dp[1] = stairs[1];
	dp[2] = dp[1] + stairs[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	cout << dp[n] << endl;
}