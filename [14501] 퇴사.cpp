// [14501] 퇴사
// https://www.acmicpc.net/problem/14501
// dp, 브루트 포스

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, next, n1, n2;
    vector <int> t;
    vector <int> p;
    int dp[20];
    t.push_back(0), p.push_back(0); // 시작 인덱스를 1로 하기 위해

    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> n1 >> n2;
        t.push_back(n1); p.push_back(n2);
    }

    dp[n + 1] = 0;
    for(int i = n ; i > 0 ; i--) {
        next = i + t[i];

        /* 
        n = 7, t[7] = 1 인 경우 7일째의 상담도 할 수 있기 때문에 
        next는 (7 + 1) = 8 까지도 가능
        -> next > n + 1 일 때만 dp[i] = dp[i + 1]
        */
        if(next > n + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + p[i]);
        }
    }

    cout << dp[1] << endl;
}