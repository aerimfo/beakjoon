// [11660] 구간 합 구하기 5
// dp
// dp[i][j] = (1, 1) ~ (i, j)까지의 합
#include <iostream>
using namespace std;

int n, m, num[1025][1025], dp[1025][1025];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum = 0, x_1, x_2, y_1, y_2;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> num[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << dp[x_2][y_2] - dp[x_2][y_1 - 1] - dp[x_1 - 1][y_2] + dp[x_1 - 1][y_1 -1] << '\n';
    }

    return 0;
}