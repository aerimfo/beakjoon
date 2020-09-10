// [10942] 팰린드롬?
// https://www.acmicpc.net/problem/10942

#include <cstdio>

int num[2000];
bool dp[2000][2000];

int go(int i, int j) 
{ 
    // 길이가 1인 부분 수열은 무조건 팰린드롬
    if (i == j) {
        return 1;
    }
    // 길이가 2인 부분 수열 
    else if (i + 1 == j) {
        // 두 수가 같다면 팰린드롬
        if (num[i] == num[j]) return 1;
        else return 0;
    }
    // 팰린드롬
    if (dp[i][j] > 0) return dp[i][j];

    // 처음과 마지막 숫자가 다르다면 팰린드롬은 될 수 없음
    if (num[i] != num[j]) {
        return dp[i][j] = 0; 
    }
    // 처음과 마지막 숫자가 같다면 팰린드롬이 될 가능성이 있음
    else {
        // 그 사이의 수들이 팰린드롬인지를 재귀함수를 통하여 확인
        return dp[i][j] = go(i + 1,j - 1);
    }
}

int main(void) 
{
    int m, n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", go(s - 1, e - 1));
    }
}