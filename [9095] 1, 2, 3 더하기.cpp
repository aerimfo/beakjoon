// [9095] 1, 2, 3 더하기 
// https://www.acmicpc.net/problem/9095
// dp(Bottom-up)

#include <iostream>
using namespace std;

int main(void)
{
	int t, n; // the number of test cases
	int arr[12] = { 0, 1, 2, 4, };
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 4; j <= n; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		cout << arr[n] << endl;
	}
}