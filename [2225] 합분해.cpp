/*[2225] ÇÕºÐÇØ*/
/*https://www.acmicpc.net/problem/2225*/
/*dp*/
#include <iostream>
using namespace std;

int main(void)
{
	long dp[201][201];
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 201; i++)
	{
		dp[0][i] = 0;
		dp[1][i] = i;
		dp[i][0] = 0;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= 1000000000;
		}
	}
	cout << dp[n][k] << endl;
}