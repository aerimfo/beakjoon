/*[11726] 2xn ≈∏¿œ∏µ*/
/*https://www.acmicpc.net/problem/11726 */

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int dp[1001] = { 0 };
	cin >> n;
	dp[0] = 0, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	cout << dp[n];
}