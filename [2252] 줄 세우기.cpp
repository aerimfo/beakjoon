// [2252] 줄 세우기
// 그래프, 위상 정렬, DAG
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m, inDegree[32001], ans[32001];
vector<int> v[32001];

void solution()
{
    int idx = 0;
    deque<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push_back(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop_front();
        ans[idx++] = cur;
        for(int next: v[cur]) {
            // next를 가리키고 있던 간선 하나가 사라졌으므로(cur) inDegree 1 감소
            if((--inDegree[next]) == 0) { 
                q.push_back(next); // inDegree가 0이면 큐에 추가
            }
        }
    }
}

void output()
{
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }
    solution();
    output();
    return 0;
}