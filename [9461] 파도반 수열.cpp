/*[9461] 파도반 수열*/
/*https://www.acmicpc.net/problem/9461*/
/*dp*/
#include <iostream>
using namespace std;

int main(void)
{
	long dp[101]; /*The value of dp is out of range of int at some point*/
	int t, n;
	cin >> t;/*the number of test cases*/
	dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 4; j <= n; j++)
			dp[j] = dp[j - 2] + dp[j - 3];
		cout << dp[n] << endl;
	}
}