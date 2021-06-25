// [1463] 1로 만들기
// https://www.acmicpc.net/problem/1463
// dp

#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX] = {0}; // 최소 연산 횟수

void minCal(int n)
{
    dp[n] = dp[n-1] + 1;

    if(n % 2 == 0) {
        dp[n] = dp[n] > dp[n/2] + 1 ? dp[n/2] + 1 : dp[n];
    }

    if(n % 3 == 0) {
        dp[n] = dp[n] > dp[n/3] + 1 ? dp[n/3] + 1 : dp[n];
    }
}

int main(void)
{
    int n;
    cin >> n;

    dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 1;

    for(int i = 4 ; i <= n ; i++) {
        minCal(i);
    }

    cout << dp[n] << '\n';

    return 0;
}