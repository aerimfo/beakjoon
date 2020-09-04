// [11048] 이동하기
// https://www.acmicpc.net/problem/11048

#include <iostream>
using namespace std;
int max(int a, int b, int c);

int main(void)
{
    int n, m, tmp;
    int candy[1002][1002], dp[1002][1002];
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin >> tmp;
            candy[i][j] = tmp;
        }
    }
    
    dp[0][0] = 0, dp[0][1] = 0, dp[1][0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + candy[i][j];
        }
    }

    cout << dp[n][m];
}

int max(int a, int b, int c)
{
    int maxValue = a;
    if(b > maxValue)
        maxValue = b;
    if(c > maxValue)
        maxValue = c;

    return maxValue;
}