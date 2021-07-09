// [9095] 1, 2, 3 더하기 
// https://www.acmicpc.net/problem/9095
// dp(Top-down)

#include <iostream>
using namespace std;

int dp[11] { 0, 1, 2, 4, };

int go(int n) 
{
    if(dp[n] != 0) return dp[n];
    
    dp[n] += go(n-3);
    dp[n] += go(n-2);
    dp[n] += go(n-1);
    
    return dp[n];
}

int main(void)
{
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        cout << go(n) << '\n';
    }
}