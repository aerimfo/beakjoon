// [2606] 바이러스
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
using namespace std;

int computers, connectedComputers, visited[101], ans;
vector <int> computerVec[101];

void input()
{
    int u, v;
    cin >> computers >> connectedComputers;
    for(int i = 0; i < connectedComputers; i++) {
        cin >> u >> v;
        computerVec[u].push_back(v); computerVec[v].push_back(u);
    }
}

void dfs(int start)
{
    visited[start] = true;

    for(int i = 0; i < computerVec[start].size(); i++) {
        if(visited[computerVec[start][i]] == false) {
            ans++;
            dfs(computerVec[start][i]);
        }
    }
}

int main(void)
{
    input();
    dfs(1);
    cout << ans << '\n';
}