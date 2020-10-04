// [8895] 막대 배치
// https://www.acmicpc.net/problem/8895

#include <iostream>
using namespace std;

long long dp[25][25][25];
 
void arrange()
{
    for(int i = 2 ; i <= 20 ; i++) {
        for(int j = 1 ; j <= i ; j++) {
            for(int k = 1 ; k <= i ; k++) {
                // 높이가 1인 막대가 기준
                // 기준 막대가 가장 왼쪽 + 기준 막대가 가장 오른쪽 + 기준 막대가 그 이외의 위치에 있는 경우
                dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + (i-2)*dp[i-1][j][k];
            }
        }
    }
}
 
int main()
{
    int t, n, l, r;
    cin >> t;
    dp[1][1][1] = 1; // initialization

    while(t--){
        cin >> n >> l >> r;
        arrange();
        cout << dp[n][l][r];
    }
    return 0;
}