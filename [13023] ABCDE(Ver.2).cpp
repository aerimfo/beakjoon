// [13023] ABCDE
// dfs
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[2001];
vector<int> friendsInfo[2001];

void dfs(int x, int depth) 
{
    if(depth == 4) {
        cout << "1\n";
        exit(0);
    }
    visited[x] = true;
    for(int i = 0; i < friendsInfo[x].size(); i++) {
        int next = friendsInfo[x][i];
        if(visited[next] == false) {
            dfs(next, depth + 1);
        }
    }
    visited[x] = false; // 중요
}

int main(void)
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        friendsInfo[a].push_back(b);
        friendsInfo[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, 0); // dfs(출발점, 깊이)
    }
    cout << "0\n"; // dfs에서 종료되지 못한 경우
    return 0;
}