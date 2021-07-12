// [16194] 카드 구매하기2
// https://www.acmicpc.net/problem/16194
// dp

#include <iostream>
using namespace std;

int main(void)
{
    int n, minCost;
    int p[1001] = {0}, dp[1001] = {0};
    cin >> n;

    for(int i = 1 ; i <= n ; i++) {
        cin >> p[i];
    }

    dp[0] = 0, dp[1] = p[1], minCost = p[1];
    for(int i = 2 ; i <= n ; i++) {
        minCost = p[i];
        for(int j = 1 ; j < i ; j++) {
            if(dp[j] + p[i-j] < minCost) {
                minCost = dp[j] + p[i-j];
            }
        }
        dp[i] = minCost;
    }

    cout << dp[n] << '\n';
}