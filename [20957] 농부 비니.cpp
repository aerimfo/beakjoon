// [20957] 농부 비니
// https://www.acmicpc.net/problem/20957
// 수학, dp, 정수론
// 수를 구성하는 모든 숫자의 곱이 7의 배수 -> 숫자 0 또는 7이 1번 이상 등장
/* dp[i][j][k] = 다음 3가지 조건을 만족하는 정수의 개수 
    i → i자리 양의 정수
    j → j = 0인 경우, 수를 구성하는 숫자에 0과 7이 포함되지 않음
        j = 1인 경우, 수를 구성하는 숫자에 0 또는 7이 1번 이상 포함됨
    k → 수를 구성하는 모든 숫자의 합을 7로 나눈 나머지가 k */

#include <iostream>
#include <cstdio>
using namespace std;

int dp[10001][2][7];

void find()
{
    // 초기값
    for (int i = 1; i < 10; i++) {
        dp[1][i % 7 == 0 ? 1 : 0][i % 7]++;
    }

    for(int i = 1 ; i < 10000 ; i++) {
        for(int j = 0 ; j <= 1 ; j++) {
            for(int k = 0 ; k < 7 ; k++) {
                for(int l = 0 ; l < 10 ; l++) {
                    //printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
                    dp[i + 1][l == 0 || l == 7 ? 1 : j][(k + l) % 7] += dp[i][j][k];
                    dp[i + 1][l == 0 || l == 7 ? 1 : j][(k + l) % 7] %= 1000000007;
                }
            }
        }
    }
}

int main(void)
{
    int t, n;
    cin >> t;

    find();
    
    while(t--) {
        cin >> n;
        cout << dp[n][1][0] << '\n';
    }
}