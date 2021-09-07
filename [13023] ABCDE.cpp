// [13023] ABCDE
// https://www.acmicpc.net/problem/13023
// 그래프, dfs

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
bool visited[2001];
vector<int> friends[2001];

void input()
{
    int a, b;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        friends[a].push_back(b); friends[b].push_back(a);
    }
}

void dfs(int start, int cnt)
{
    if(cnt == 5) {
        cout << "1" << '\n';
        exit(0);
    }
    visited[start] = true; 
    for (int i = 0; i < friends[start].size(); i++) { 
        int next = friends[start][i]; 
        if (visited[next] == false) dfs(next, cnt + 1); 
    }
    visited[start] = false;
}

int main(void)
{
    input();
    for(int i = 0 ; i < n ; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, 1);
    }
    cout << "0" << '\n';
    return 0;
}