// [1509] 팰린드롬 분할
// https://www.acmicpc.net/problem/1509
// dp

#include <iostream>
#include <string>
using namespace std;

bool check[2501][2501];
int dp[2501];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s; // 시작 인덱스를 1로 하기 위해

    // 길이가 1인 수열은 무조건 팰린드롬
    for(int i = 1 ; i <= n ; i++) {
        check[i][i] = true;
    }

    // 길이가 2인 수열은 두 수가 같은 경우 팰린드롬
    for(int i = 1 ; i <= n - 1 ; i++) {
        if(s[i] == s[i + 1]) {
            check[i][i + 1] = true;
        }
    }

    // 길이가 3이상인 수열
    for(int k = 2 ; k < n ; k++) { 
        for(int i = 1 ; i <= n - k ; i++) {
            int j = i + k; 
            // 처음과 마지막 수가 같고, 그 사이의 수들이 팰린드롬이면 팰린드롬
            check[i][j] = (s[i] == s[j] && check[i + 1][j - 1]);
        }
    }

    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++) { 
        dp[i] = -1; 
        for(int j = 1 ; j <= i ; j++) { 
            // 팰린드롬이라면
            if(check[j][i]) { 
                if(dp[i] == -1 || dp[i] > dp[j - 1] + 1) { 
                    dp[i] = dp[j - 1] + 1; 
                }
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}