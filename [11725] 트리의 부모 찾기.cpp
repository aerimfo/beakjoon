// [11725] 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
using namespace std;

int n; // 노드의 개수
bool visited[100001] = {false};
int parent[100001];
vector <int> tree[100001];

void dfs(int start)
{
    visited[start] = true;
    for(int i = 0 ; i < tree[start].size() ; i++) {
        int next = tree[start][i];
        if(visited[next] == false) {
            parent[next] = start; // 부모 노드부터 탐색하기 때문에 연결되어있고 방문하지 않은 다음 노드는 무조건 자식 노드
            dfs(next);
        }
    }
}

int main(void)
{
    int n1, n2; // 두 정점
    cin >> n;
    for(int i = 0 ; i < n-1 ; i++) {
        cin >> n1 >> n2;
        tree[n1].push_back(n2); tree[n2].push_back(n1);
    }
    
    parent[tree[1][0]] = 1; parent[tree[1][1]] = 1; // 1번 노드와 연결되어있는 노드들의 부모는 1
    dfs(1);

    for(int i = 2 ; i <= n ; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}