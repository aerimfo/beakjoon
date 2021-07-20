// [14002] 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002
// dp, LIS
// dp[i] = a[i]를 마지막 수로 가지는 LIS의 길이
// link[i] = a[i]를 마지막 수로 가지는 LIS에서 a[i]바로 이전 수의 인덱스

#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;

int main(void)
{
    int n;
    int a[1001], dp[1001] = {0}, link[1001];
    vector <int> ans; // LIS 구성하는 수열
    cin >> n;

    // 수열 입력
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    } 

    memset(link, -1, sizeof(link));

    dp[0] = 1, link[0] = -1;
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            if(a[j] < a[i]) {
                if(dp[j] > dp[i]) {
                    dp[i] = dp[j];
                    link[i] = j;
                }
            }
        }
        dp[i]++; // arr[i] 추가
    }

    // 가장 긴 LIS 길이 찾기
    int max = 0, maxIndex; // 가장 긴 LIS의 길이, 가장 긴 LIS를 구성하는 수열의 마지막 원소 인덱스
    for(int i = 0 ; i < n ; i++) {
        if(dp[i] > max) {
            max = dp[i];
            maxIndex = i;
        }
    }

    cout << max << '\n';

    int idx = maxIndex;
    while(idx != -1) {
        ans.push_back(a[idx]);
        idx = link[idx];
    }

    // LIS 출력
    for(int i = ans.size() - 1 ; i >= 0 ; i--) {
        cout << ans[i] << " ";
    }
}