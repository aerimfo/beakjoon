// [1890] 점프
// https://www.acmicpc.net/problem/1890

#include <iostream>
using namespace std;

long long dp[101][101];
int jump[101][101];

int main(void)
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            cin >> jump[i][j];
        }
    }
    dp[1][1] = 1;
    
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(i == 1 && j == 1) continue;
            // 왼쪽에서 온 경우
            for(int k = 1 ; k < j ; k++) {
                if(k + jump[i][k] == j) {
                    dp[i][j] += dp[i][k];
                }
            }
            // 위쪽에서 온 경우
            for(int k = 1 ; k < i ; k++) {
                if(k + jump[k][j] == i) {
                    dp[i][j] += dp[k][j];
                }
            }
        }
    }
    cout << dp[n][n] << '\n';
}