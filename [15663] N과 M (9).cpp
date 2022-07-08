// [15663] N과 M (9)
// 백트래킹
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, pre = 0, arr[8];
bool visited[8];
vector <int> num;

void dfs(int cnt)
{
    // pre = 0; -> 답 제대로 안나옴. 왜..?
    int pre = 0; // 7 9 -> 9 1 가능하도록

    if(cnt == m) {
        for(int i = 0 ; i < m ; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        if(visited[i] == false && num[i] != pre) {
            visited[i] = true; 
            arr[cnt] = num[i]; // 선택한 숫자 저장
            pre = num[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tmp;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    dfs(0);
    return 0;
}