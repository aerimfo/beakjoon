// [17404] RGB거리 2
// https://www.acmicpc.net/problem/17404
// dp

#include <iostream>
using namespace std;

int main(void)
{
    int n, ans = 1000010; // 집의 수, 정답
    int cost[1001][3]; // 각 집을 빨강, 초록, 파랑으로 칠하는 비용
    int dp[1001][3]; // i번째 집을 빨강, 초록, 파랑으로 칠할 때의 최소 비용 
    cin >> n;

    for(int i = 1 ; i <= n ; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for(int i = 0 ; i < 3 ; i++) { // 빨강, 초록, 파랑
        dp[1][0] = 1000010; dp[1][1] = 1000010; dp[1][2] = 1000010; // 선택되지 않도록 매우 큰 값으로 초기화
        dp[1][i] = cost[1][i]; // 첫번째 집을 현재 색깔로 고정

        // 첫번째 집을 고정했을 때 나머지 집을 색칠하는 최소 비용(마지막 집도 일단 계산)
        for(int j = 2 ; j <= n ; j++) {
            dp[j][0] = cost[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = cost[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = cost[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }

        /* (첫번쨰 집 빨강 + 마지막 집 초록 or 파랑) 
            vs (첫번쨰 집 초록 + 마지막 집 빨강 or 파랑)
            vs (첫번쨰 집 파랑 + 마지막 집 빨강 or 초록) */
        for(int j = 0 ; j < 3 ; j++) {
            // 첫번째 집이랑 마지막 집의 색깔이 같은 경우 -> 제외
            if(i == j) continue;
            else ans = min(ans, dp[n][j]);
        }
    }

    cout << ans << '\n';
}