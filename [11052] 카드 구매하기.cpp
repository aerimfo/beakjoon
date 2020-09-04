// [11052] 카드 구매하기
// https://www.acmicpc.net/problem/11052

#include <iostream>
using namespace std;
int p[10001];

int main(void)
{
    int dp[1001]; 
    int n; // 민규가 구매하려고 하는 카드의 개수
    int max; // 지불해야 하는 금액의 최댓값
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> p[i];
    }
    p[0] = 0, dp[0] = 0, dp[1] = p[1];
    for(int i = 2 ; i <= n ; i++) {
        max = dp[1];
        for(int j = i ; j > 0 ; j--) {
            if(p[j] + dp[i-j] > max) {
                dp[i] = max = p[j] + dp[i-j];
            }
        }
    }
    cout << dp[n] << endl;
}