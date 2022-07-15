// [7579] 앱
// dp
// dp[i][j] = i번째 앱까지 고려했을 때 최소 j만큼의 비용을 들여서 확보할 수 있는 메모리
#include <iostream>
#include <cmath>
using namespace std;

int n, m, bytes[101], cost[101], dp[101][10001];

void solution()
{
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < cost[i]; j++) { // i번재 앱 종료 X
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = cost[i]; j < 10001; j++) { // i번째 앱 종료
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + bytes[i]);
        }
    }
}

void printAns()
{
    for(int i = 0; i < 10001; i++) {
        if(dp[n][i] >= m) {
            cout << i << '\n';
            break;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> bytes[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    solution();
    printAns();

    return 0;
}