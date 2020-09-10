// [1890] 점프
// https://www.acmicpc.net/problem/1890
// dp

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
            // 칸에 적힌 수가 0인 경우 더 이상 진행 할 수 없음
            if(jump[i][j] == 0) continue;
            
            // 오른쪽으로 이동하는 경우
            if (j + jump[i][j] <= n) {
                dp[i][j + jump[i][j]] += dp[i][j];
            }
            
            // 아래쪽으로 이동하는 경우
            if (i + jump[i][j] <= n) {
                dp[i + jump[i][j]][j] += dp[i][j];
            }
        }
    }
    cout << dp[n][n] << '\n';
}