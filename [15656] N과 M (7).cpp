// [15656] N과 M (7)
// https://www.acmicpc.net/problem/15656
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
        arr[cnt] = num[i]; // 선택한 숫자 저장
        dfs(cnt + 1);
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