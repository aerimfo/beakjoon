// [1463] 1로 만들기
// https://www.acmicpc.net/problem/1463
// dp

#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX] = {0}; // 최소 연산 횟수

int main(void)
{
    int n;
    cin >> n;

    dp[0] = 0, dp[1] = 0;

    for(int i = 2 ; i <= n ; i++) {
        dp[i] = dp[i-1] + 1;
 
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }

        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}