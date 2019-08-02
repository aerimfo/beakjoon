/*[1699] 제곱수의 합*/
/*https://www.acmicpc.net/problem/1699 */
/*dp*/

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n, temp = 0, j, min = 0;
	int dp[100100] = { 0 };
	dp[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (j = 1;; j++)
			if ((pow(j, 2) <= i) && (i < pow(j + 1, 2)))
				break;
		min = dp[i - 1];
		for (int k = 1; k <= j; k++)
		{
			temp = pow(k, 2);
			/*if i=10,
			  dp[10] = min(dp[10-1], dp[10-4], dp[10-9]) + 1*/
			if (dp[i - temp] < min)
				min = dp[i - temp];
		}
		dp[i] = min + 1;
	}
	cout << dp[n];
}