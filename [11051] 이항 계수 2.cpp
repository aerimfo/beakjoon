// [11051] 이항 계수 2
// https://www.acmicpc.net/problem/11051
// dp
// dp[n][r] = nCr

#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    int dp[1002][1002];
    cin >> n >> k;
    dp[0][0] = 1; dp[0][1] = 0; 
    for(int i = 1 ; i <= n ; i++) {
        dp[i][0] = 1; // nC0 = 1
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= k && j <= i ; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }

    cout << dp[n][k] << endl;
}