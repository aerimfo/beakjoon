/*[2133] 타일 채우기*/
/*https://www.acmicpc.net/problem/2133*/

#include <iostream>
using namespace std;

int main(void)
{
	int n, sum = 0;
	int dp[31];
	cin >> n;
	dp[0] = 0, dp[2] = 3;
	for (int i = 1; i < 31; i = i + 2)
		dp[i] = 0;
	for (int i = 4; i <= n; i = i + 2)
	{
		for (int j = 2; j <= i - 4; j = j + 2)
			sum += dp[j];
		dp[i] = dp[i - 2] * dp[2] + sum * 2 + 2;
		sum = 0;
	}
	cout << dp[n];
}