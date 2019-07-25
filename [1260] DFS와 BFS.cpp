#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
/*https://www.acmicpc.net/problem/1260*/
using namespace std;

bool visit[MAX];
vector<int>list[MAX];
void dfs(int start);
void bfs(int start);

int main(void)
 {
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++)
	{
		int u, v; /*간선의 양 끝 점*/
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	for(int i=1;i<=N;i++)
		sort(list[i].begin(), list[i].end());
	dfs(V);
	for (int i = 1; i <= N; i++)
		visit[i] = false;
	cout << endl;
	bfs(V);
}

void dfs(int start)
{
	visit[start] = true; /*현재 노드 방문 표시*/
	cout << start << " "; /*출력*/
	for (int i = 0; i < list[start].size(); i++)
	{
		/*현재 노드에서 이동할 수 있는 다음 노드 찾기*/
		int next = list[start][i];
		if (visit[next] == false) /* 다음 노드가 아직 방문한 적 없는 노드라면*/
			dfs(next); /*다음 노드로 이동*/
	}
}

void bfs(int start)
{
	queue<int>q;
	visit[start] = true; /*방문*/
	q.push(start); /*큐에 시작노드 push*/
	while (!q.empty()) /*큐가 빌 때까지 반복*/
	{
		int now = q.front(); /*now = 큐의 제일 앞 원소*/
		q.pop();
		cout << now << " "; /*pop될 때 방문했다, 출력*/
		for (int i = 0; i < list[now].size(); i++)
		{
			/*현재 노드에서 이동할 수 있는 다음 노드(next) 찾기*/
			int next = list[now][i]; /*next에 차례로 2, 5, 6*/
			while (visit[next] == false) /*다음 노드(next)가 아직 방문한 적 없는 노드라면*/
			{
				visit[next] = true; /*next를 방문했다고 표시*/
				q.push(next);
			}
		}
	}
}