// [15990] 1, 2, 3 더하기 5
// https://www.acmicpc.net/problem/15990
// dp
// dp의 자료형 주의

#include <iostream>
using namespace std;

long long dp[100001][4];

// n을 1, 2, 3의 합으로 나타내는 방법의 수
void go(int n)
{
    for(int i = 4 ; i <= n ; i++) {
        if(dp[i][1] == 0) { // 구한 적이 없다면
            dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009;
        }
    }  
}

int main(void)
{
    int t, n; 
    cin >> t;
    dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0;
    dp[2][1] = 0, dp[2][2] = 1, dp[2][3] = 0;
    
    for(int i = 1 ; i <= 3 ; i++) {
        dp[3][i] = 1;
    }

    while(t--) {
        cin >> n;
        go(n);
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
    }
}