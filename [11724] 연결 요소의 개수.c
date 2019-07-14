/*[11724] 연결 요소의 개수*/
/*dfs가 새롭게 호출된 횟수 = 연결 요소의 개수*/
#include <stdio.h>
#define MAX 1001

int n, m; /*정점의 개수, 간선의 개수*/
int visit[MAX];
int matrix[MAX][MAX];

void dfs(int v);

int main(void)
{
	int u, v; /*간선의 양 끝점*/
	int count = 0; /*새로 dfs가 호출된 횟수*/
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) /*노드는 1부터 시작*/
		if (!visit[i])
		{
			dfs(i);
			count++; /*dfs가 새롭게 호출된 횟수 = 연결 요소의 개수*/
		}
	printf("%d", count);
	return 0;
}

void dfs(int v)
{
	for (int i = 1; i <= n; i++)
		if (matrix[v][i] == 1 && !visit[i])
		{
			visit[i] = 1; /*방문함*/
			dfs(i);
		}
}