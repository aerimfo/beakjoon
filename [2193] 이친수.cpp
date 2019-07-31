/*[2193] ÀÌÄ£¼ö*/
/*https://www.acmicpc.net/problem/2193 */
#include <iostream>
using namespace std;

#define MAX 1000000

int main(void)
{
	int n;
	long dp[MAX];
	dp[0] = 0, dp[1] = 1, dp[2] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
}