// [1309] 동물원
// https://www.acmicpc.net/problem/1309
// dp

#include <cstdio>

int main(void)
{
    int n, dp[100001];
    scanf("%d", &n);
    dp[0] = 1; dp[1] = 3;
    
    for(int i = 2 ; i <= n ; i++) {
        dp[i] = (dp[i - 1]*2 + dp[i - 2]) % 9901;
    }

    printf("%d\n", dp[n]);
}