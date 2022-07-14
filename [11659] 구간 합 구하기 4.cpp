// [11659] 구간 합 구하기 4
// dp
// dp[i] = i번째 수까지의 합
#include <iostream>
using namespace std;

int n, m, num[100001], dp[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int i, j;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++) {
        cin >> num[i];
        dp[i] = dp[i-1] + num[i];
    }

    for(int k = 0; k < m; k++) {
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }
    return 0;
}