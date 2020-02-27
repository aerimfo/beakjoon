// [2011] 암호코드
// https://www.acmicpc.net/problem/2011
// dp

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int dp[5001] = { 0 };
	int len;
	string code;

	cin >> code;
	len = code.length();
	code = " " + code; // index가 1부터 시작하기 위해서
	dp[0] = 1;

	for (int i = 1; i <= len; i++) {
		int n = code[i] - '0';
		if ((1 <= n) && (n <= 9)) {
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		}
		if (i == 1)
			continue;
		if (code[i - 1] == '0')
			continue;

		n = ((code[i - 1] - '0') * 10 + (code[i] - '0'));

		if ((10 <= n) && (n <= 26)) {
			dp[i] += dp[i - 2];
			dp[i] %= 1000000;
		}
	}
	cout << dp[len] << endl;
	return 0;
}