//[1932] Á¤¼ö »ï°¢Çü
//https://www.acmicpc.net/problem/1932

#include <iostream>
#include <algorithm>
using namespace std;

int dp[505][505];
int triangle[505][505];

int main(void)
{
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sum = max(sum, dp[n][i]);
	}

	cout << sum << endl;
}