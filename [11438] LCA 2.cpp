// [11438] LCA 2
// 트리, 최소 공통 조상(LCA)
#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <cmath>
using namespace std;

int n, m, maxLevel, depth[100001], parent[18][100001];
vector<int> v[100001];

void getDepth()
{
    memset(depth, -1, sizeof(depth));
    deque<int> dq;
    dq.push_back(1); // 루트 노드부터 탐색 시작
    depth[1] = 0; // 방문 처리

    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        for(int next: v[cur]) {
            if(depth[next] == -1) { // 방문 안함
                dq.push_back(next);
                depth[next] = depth[cur] + 1;
                parent[0][next] = cur; // next의 2^0 번째 조상은 cur
            }
        }
    }
}

// 각 정점의 2^k 번째 조상 찾기
void getMinTable()
{
    for(int r = 1; r < 18; r++) {
        for(int i = 1; i <= n; i++) {
            parent[r][i] = parent[r-1][parent[r-1][i]]; // parent[r][i]은 parent[r-1][i]의 2^(r-1)번째 부모
        }
    }
}

int LCA(int v1, int v2)
{
    // 1. Depth 맞추기
    // 항상 v1의 depth가 v2의 depth보다 크도록
    int maxLevel = (int)floor(log2(n));
    if(depth[v1] != depth[v2]) {
        if(depth[v1] < depth[v2]) {
            int tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
    }
    for(int i = maxLevel; i >= 0; i--) {
        if(depth[v2] <= depth[parent[i][v1]]) {
            v1 = parent[i][v1];
        }
    }

    // 2. LCA 찾기
    int lca = v2;
    if(v1 != v2) {
        for(int i = maxLevel; i >= 0; i--) {
            if(parent[i][v1] != parent[i][v2]) {
                v1 = parent[i][v1];
                v2 = parent[i][v2];
            }
            lca = parent[i][v1];
        }
    }
    return lca;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int e1, e2, v1, v2;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> e1 >> e2;
        v[e1].push_back(e2);
        v[e2].push_back(e1);
    }
    getDepth();
    getMinTable();
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        cout << LCA(v1, v2) << '\n';
    }
    return 0;
}