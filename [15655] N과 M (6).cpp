// [15655] N과 M (6)
// https://www.acmicpc.net/problem/15655
// 백트래킹

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
bool visited[10];
vector <int> num;

// cnt = 현재까지 선택한 숫자의 개수
void dfs(int cnt)
{
    // m개를 모두 선택했다면
    if(cnt == m) {
        for(int i = 0 ; i < m ; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        if(visited[i] == false && arr[cnt - 1] < num[i]) { // 선택한 적이 없고 직전에 선택한 수보다 크다면
            visited[i] = true; // 선택
            arr[cnt] = num[i]; // 선택한 숫자 저장
            dfs(cnt + 1);
            visited[i] = false;
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