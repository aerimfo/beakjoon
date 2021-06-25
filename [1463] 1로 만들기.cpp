// [1463] 1로 만들기
// https://www.acmicpc.net/problem/1463
// dp

#include <iostream>
#define MAX 1000001
using namespace std;

int dp[MAX] = {0}; // 최소 연산 횟수

void minCal(int x)
{
    dp[x] = dp[x-1] + 1;

    if(x % 2 == 0) {
        dp[x] = dp[x] > dp[x/2] + 1 ? dp[x/2] + 1 : dp[x];
    }

    if(x % 3 == 0) {
        dp[x] = dp[x] > dp[x/3] + 1 ? dp[x/3] + 1 : dp[x];
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