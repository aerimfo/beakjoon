/*[1904] 01≈∏¿œ*/
/*https://www.acmicpc.net/problem/1904*/
#include <stdio.h>

int main(void)
{
	int n;
	long dp[1000001] = { 0 };
	dp[0] = 0, dp[1] = 1, dp[2] = 2;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 15746;
	}
	printf("%d", dp[n]);
}