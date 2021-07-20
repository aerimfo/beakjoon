// [15988] 1, 2, 3 더하기 3
// https://www.acmicpc.net/problem/15988
// dp

#include <iostream>
using namespace std;

int main(void)
{
    int t, n;
    long long dp[1000001] = {0};

    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4;
    cin >> t;

    while(t--) {
        cin >> n;
        for(int i = 4 ; i <= n ; i++) {
            if(dp[i] == 0) {
                dp[i] += (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
            }            
        }

        cout << dp[n] % 1000000009 << '\n';
    }
    return 0;
}