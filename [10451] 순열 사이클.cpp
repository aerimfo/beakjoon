// [10451] 순열 사이클
// https://www.acmicpc.net/problem/10451
// dfs, bfs
/* ***순열의 크기는 최대 1000이고 그래프의 index는 1부터 시작하기 때문에 
   배열의 크기는 최소 1001로 잡아야 함*** */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void bfs(int s);
bool check[1001];
vector<int> a[1001];
int n, cnt;
queue<int> q;

int main(void)
{
	int t, v;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;

		// initialization
		memset(check, false, sizeof(check));
		while (!q.empty())
			q.pop();

		for (int j = 1; j <= n; j++) {
			a[j].clear(); // initialization
			cin >> v;
			a[j].push_back(v);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				bfs(i);
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}

void bfs(int s)
{
	check[s] = true; q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int next = a[x][i];
			if (check[next] == false) {
				check[next] = true; q.push(next);
			}
		}
	}
	cnt++;
}