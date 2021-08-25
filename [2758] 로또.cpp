// [2758] 로또
// https://www.acmicpc.net/problem/2758
// dp
// dp[i][j]  = i개의 수 사용, 마지막 수가 j인 로또의 경우의 수
// dp[i][j] = dp[i-1][1] ~ dp[i-1][j/2]

#include <iostream>
using namespace std;

long long dp[11][2001];

void lotto()
{
    for (int i = 1; i <= 2000; i++) {
		dp[1][i] = 1;
	}

    for(int i = 2 ; i <= 10 ; i++) {
        for(int j = 1 ; j <= 2000 ; j++) {
            for(int k = 1 ; k <= j/2 ; k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
}

int main(void)
{
    int t, n, m;
    long long ans = 0;
    cin >> t;
    lotto();
    while(t--) {
        cin >> n >> m;
        ans = 0;
        for(int i = 1 ; i <= m ; i++) {
            ans += dp[n][i];
        }
        cout << ans << '\n';
    }
}