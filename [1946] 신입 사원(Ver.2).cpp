// [1946] 신입 사원(Ver.2)
// https://www.acmicpc.net/problem/1946
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > info;
vector<int> ans;

void getMaxNum()
{
    // 서류 심사 성적이 1등인 사람이 면접 성적은 꼴등일 수 있음 -> 그래도 선택되도록 minRank = n + 1로 초기화 
    int minRank = n + 1, cnt = 0;
    sort(info.begin(), info.end());
    for(int i = 0 ; i < n ; i++) {
        if(info[i].second < minRank) {
            minRank = info[i].second;
            cnt++;
        }
    }
    ans.push_back(cnt);
    info.clear();
}

void input()
{
    int t, document, interview;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            cin >> document >> interview;
            info.push_back(make_pair(document, interview));
        }
        getMaxNum();
    }
}

void output()
{
    for(int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << '\n';
    }
}

int main(void)
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    input();
    output();
}