// [7568] 덩치
// https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(void)
{
    int n, cnt = 0; // 사람의 수, 자신보다 덩치가 큰 사람의 수
    int x, y; // 몸무게, 키
    vector <int> rank; // 등수 
    vector <pair<int, int> > info;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> x >> y;
        info.push_back(make_pair(x, y));
    }
    for(int i = 0 ; i < n ; i++) {
        cnt = 0;
        for(int j = 0 ; j < n ; j++) {
            if(j == i) continue;
            if(info[i].first < info[j].first) {
                if(info[i].second < info[j].second) {
                    cnt++;
                }
            }
        }
        rank.push_back(cnt + 1);
    }
    for(int i = 0 ; i < n ; i++) {
        cout << rank[i] << " ";
    }
}