// [2294] 동전 2
// https://www.acmicpc.net/problem/2294
// dp

#include <cstdio>
int value[101], dp[10001];

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d", &value[i]);
    }

    dp[0] = 0; // 0원을 만드려면 동전 0개를 사용해야 함

    // 초기화(굳이 10001일 필요는 없음, 그냥 아주 큰 값으로 설정)
    for(int i = 1 ; i <= k ; i++) {
        dp[i] = 10001;
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = value[i] ; j <= k ; j++) {
            if(dp[j] > dp[j - value[i]] + 1) {
                dp[j] = dp[j - value[i]] + 1;
            }
        }
    }
    // 가능한 경우
    if(dp[k] != 10001) {
        printf("%d\n", dp[k]);
    }
    // 불가능한 경우
    else {
        printf("-1");
    }
}