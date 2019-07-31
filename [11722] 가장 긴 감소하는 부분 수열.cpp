/*[11722] 가장 긴 감소하는 부분 수열*/
/*https://www.acmicpc.net/problem/11722 */
/*dp*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n; /*size of the sequence*/
	int dp[1001], a[1001];
	int num = 0; /*The length of the longest decreasing partial sequence*/
	dp[0] = 1;
	cin >> n;
	for (int i = 0; i < n; i++) /*input*/
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		int maxl = 0;
		for (int j = 0; j < i; j++)
			if (a[j] > a[i])
				maxl = max(maxl, dp[j]);
		dp[i] = maxl + 1;
	}

	/*Find max value among the values stored in dp []*/
	for (int i = 0; i < n; i++)
		if (dp[i] > num)
			num = dp[i];
	cout << num << endl;
}