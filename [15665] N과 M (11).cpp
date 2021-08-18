// [15665] N과 M (11)
// https://www.acmicpc.net/problem/15665
// 백트래킹

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, pre = 0;
int arr[8];
bool visited[8];
vector <int> num;

// cnt = 현재까지 선택한 숫자의 개수
void dfs(int cnt)
{
    // pre = 0; -> 답 제대로 안나옴. 왜..?
    int pre = 0; // 7 9 -> 9 1 가능하도록

    // m개를 모두 선택했다면
    if(cnt == m) {
        for(int i = 0 ; i < m ; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        if(num[i] != pre) {
            arr[cnt] = num[i]; // 선택한 숫자 저장
            pre = num[i];
            dfs(cnt + 1);
        }
    }
}

int main(void)
{
    int tmp;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    dfs(0);
}