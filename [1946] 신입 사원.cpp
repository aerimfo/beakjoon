// [1946] 신입 사원
// https://www.acmicpc.net/problem/1946

#include <iostream>
using namespace std;

int ranking[100001];

int pick(int n) 
{
    int standard = ranking[1]; // 초기 기준 등수는 가장 낮게 설정
    // 서류 심사 결과 1등은 무조건 뽑힘
    int ans = 1;

    for(int i = 2 ; i <= n ; i++) {
        if(ranking[i] < standard) {
            ans++;
            standard = ranking[i];
        }
    }
    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i++) {
            int a, b;
            cin >> a >> b; 
            ranking[a] = b;
        }
        cout << pick(n) << '\n';
    }
    return 0;
}