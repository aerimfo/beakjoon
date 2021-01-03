// [9251] LCS(Longest Common Subsequence, 최장 공통 부분 수열)
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b)
{
    if(a > b) return a;
    else return b; 
}

int lcs(string s1, string s2)
{
    int dp[1001][1001];

    // 초기화
    for(int i = 0 ; i < s1.size() ; i++) {
        for(int j = 0 ; j < s2.size() ; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i = 1 ; i < s1.size() ; i++) {
        for(int j = 1 ; j < s2.size() ; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[s1.size()-1][s2.size()-1];
}

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;

    // 시작 인덱스를 1로 하기 위해 임의의 문자 삽입
    s1.insert(0, "0"); s2.insert(0, "0");

    cout << lcs(s1, s2) << '\n';
}