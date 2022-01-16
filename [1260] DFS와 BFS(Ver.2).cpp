// [1260] DFS와 BFS
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[1001];
int n, m, v;
vector <int> graph[1001];

void input()
{
    int v1, v2;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2); graph[v2].push_back(v1);
    }
}

void dfs(int num)
{
    cout << num << " ";
    visited[num] = true;
    for(int i = 0; i < graph[num].size(); i++) {
        if(visited[graph[num][i]] == false) {
            dfs(graph[num][i]);
        }
    }
}

void bfs(int num)
{
    memset(visited, false, sizeof(visited));
    queue <int> q;
    q.push(num);
    visited[num] = true;

    while(!q.empty()) {
        cout << q.front() << " ";
        for(int i = 0; i < graph[q.front()].size(); i++) {
            if(visited[graph[q.front()][i]] == false) {
                q.push(graph[q.front()][i]);
                visited[graph[q.front()][i]] = true;
            }
        }
        q.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(v);
    cout << '\n';
    bfs(v);
}