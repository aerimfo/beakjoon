// [10942] 팰린드롬?
// https://www.acmicpc.net/problem/10942
// dp

#include <cstdio>

int num[2000];
bool dp[2000][2000];

int main() {
    int m, n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &num[i]);
    }

    // 길이가 1인 부분 수열은 반드시 팰린드롬
    for (int i = 0 ; i < n ; i++) {
        dp[i][i] = true;
    }

    // 길이가 2인 부분 수열은 두 수가 같을 때만 팰린드롬
    for (int i = 0 ; i < n - 1 ; i++) {
        if (num[i] == num[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    // 길이가 3이상인 부분 수열
    for (int k = 3 ; k <= n ; k++) {
        for (int i = 0; i <= n - k ; i++) {
            int j = i + k - 1;
            // 처음와 마지막 수가 같고, 그 사이의 수들이 팰린드롬이라면 팰린드롬 
            if (num[i] == num[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    scanf("%d", &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s - 1][e - 1]);
    }
    return 0;
}