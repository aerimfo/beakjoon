/*[11055] 가장 큰 증가 부분 수열*/
/*https://www.acmicpc.net/problem/11055 */

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n; /*size of the sequence*/
	int a[1001], dp[1001];
	int maxsum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				sum = max(sum, dp[j]);
		dp[i] = sum + a[i];
	}
	for (int i = 0; i < n; i++)
		if (dp[i] > maxsum)
			maxsum = dp[i];
	cout << maxsum << endl;
}