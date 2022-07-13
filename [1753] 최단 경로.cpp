// [1753] 최단 경로
// 그래프, 다익스트라
#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

int V, e, k, visited[20001];
struct Info {
    int node;
    int cost; // 현재 노드까지의 누적 cost
    bool operator<(const Info &ref) const {
        return this->cost > ref.cost;
    }
};
vector<Info> vec[20001];

void solution()
{
    priority_queue<Info> pq; // cost에 대한 minHeap 형태로 동작해야 함
    for(int i = 1; i <= V; i++) {
        visited[i] = INF;
    }
    visited[k] = 0;
    pq.push({k, 0});
    while(!pq.empty()) {
        Info cur = pq.top();
        pq.pop();
        for(Info next : vec[cur.node]) {
            int cost = cur.cost + next.cost;
            if(cost < visited[next.node]) {
                visited[next.node] = cost;
                pq.push({next.node, cost});
            }
        }
    }
}

void printAns()
{
    for(int i = 1; i <= V; i++) {
        if(i == k) cout << "0\n";
        else if(visited[i] == INF) cout << "INF\n";
        else cout << visited[i] << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int u, v, w;
    cin >> V >> e;
    cin >> k;
    for(int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }
    solution();
    printAns();
    return 0;
}