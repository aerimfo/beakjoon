// [15651] N과 M (3)
// https://www.acmicpc.net/problem/15651
// 백트래킹

#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visited[10];

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

    for(int i = 1 ; i <= n ; i++) {
        arr[cnt] = i; // 선택한 숫자 저장
        dfs(cnt + 1);
    }
}

int main(void)
{
    cin >> n >> m;
    dfs(0);
}