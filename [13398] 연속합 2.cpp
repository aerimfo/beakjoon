// [13398] 연속합 2
// https://www.acmicpc.net/problem/13398
// dp
/* d[i][j] : arr[1] ~ arr[i]까지의 연속합
    1) j = 0: 값을 삭제하지 않는 경우
    2) j = 1: 값을 삭제하는 경우 */

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, ans;
    int arr[100001], dp[100001][2];
    cin >> n;
    
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    ans = arr[0];

    for(int i = 1 ; i < n ; i++) {
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]); // 0~(i-1)번째에서 값을 삭제한 경우 vs 현재 값을 삭제하는 경우
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans << '\n';
}