// [11049] 행렬 곱셈 순서
// dp
// dp[i][j] = i번째 행렬 ~ j번째 행렬까지의 최소 곱셈 연산 횟수
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int n, row[501], col[501], dp[501][501];

void solution()
{
    int ans = INT_MAX;

    /* dp 테이블 생성 순서
    dp[1][2] -> dp[2][3] -> dp[3][4] -> ... -> dp[n-1][n]
    -> dp[1][3] -> dp[2][4] -> ... -> dp[n-2][n]
    -> ...
    -> dp[1][n] */
    for(int step = 1; step < n; step++) {
        for(int start = 1; start + step <= n; start++) {
            dp[start][start + step] = INT_MAX;
            for(int mid = start; mid < start + step; mid++) {
                dp[start][start + step] = min(dp[start][start + step], 
                                dp[start][mid] + dp[mid + 1][start + step] + row[start] * col[start + step] * col[mid]);
            }
        }
    }

    cout << dp[1][n] << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> row[i] >> col[i];
    }

    solution();

    return 0;
}