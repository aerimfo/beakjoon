// [16947] 서울 지하철 2호선
// https://www.acmicpc.net/problem/16947

#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

vector<int> station[3100];
bool visited[3100], cycle[3100];
queue<pair<int, int> > q;
int n;

void input()
{
	int v1, v2;
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> v1 >> v2;
		station[v1].push_back(v2); station[v2].push_back(v1);
	}
}

// cur번 역과 순환선 사이의 거리
int bfs(int cur) {
	memset(visited, false, sizeof(visited));
	q = queue<pair<int, int> >(); 

	q.push(make_pair(cur, 0)); // (cur번 역, cur번 역과 순환선 사이의 거리)
	visited[cur] = true;

	while (!q.empty()) {
		int cur = q.front().first; 
		int cnt = q.front().second;
		q.pop();

		// 순환선이라면
		if(cycle[cur])
			return cnt;

		for (int i = 0 ; i < station[cur].size() ; i++) {
			if (!visited[station[cur][i]]) {
				q.push(make_pair(station[cur][i], cnt + 1));
				visited[station[cur][i]] = true;
			}
		}
	}
}

// 순환선 위에 존재하는 역 찾기(dfs)
void check(int cur, int start, int dep) {
	if (cur == start && dep >= 2) { // 처음 위치로 돌아옴 -> 순환선
		cycle[cur] = true;
		return;
	}
	
	visited[cur] = true;

	for (int i = 0; i < station[cur].size(); i++) {
		if (!visited[station[cur][i]]) {
			check(station[cur][i], start, dep + 1);
		}
		else if (station[cur][i] == start && dep >= 2) {
			check(station[cur][i], start, dep);
		}
	}
}

int main() {
	input();
	
	for (int i = 1 ; i <= n ; i++) {
		memset(visited, false, sizeof(visited));
		check(i, i, 0); 
	}
	
	for (int i = 1 ; i <= n ; i++) {
		if (cycle[i]) { // 순환선 위의 역이라면
			cout << "0" << " ";
		}
		else { // 아니라면
			cout << bfs(i) << " "; // 거리 계산
		}
	}

	return 0;
}