/*[1912] ¿¬¼ÓÇÕ*/
/*https://www.acmicpc.net/problem/1912 */
/*dp*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, max;
	int arr[100001], dp[100001];
	cin >> n;
	for (int i = 0; i < n; i++) /*input sequence*/
		cin >> arr[i];

	dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > dp[i - 1] + arr[i])
			dp[i] = arr[i];
		else
			dp[i] = dp[i - 1] + arr[i];
	}
	max = dp[0];
	for (int i = 0; i < n; i++)
		if (dp[i] > max)
			max = dp[i];
	cout << max << endl;
}