/*https://www.acmicpc.net/problem/11403 */

/*[11403] 경로 찾기*/
#include <stdio.h>
#define MAX 101

int n; /*정점의 개수*/
int matrix[MAX][MAX];
int visit[MAX];

void dfs(int v);

int main(void)
{
	scanf("%d", &n);

	/*인접행렬 입력, 노드는 1번부터 시작*/
	for (int i = 1; i <= n; i++) /*행*/
	{
		for (int j = 1; j <= n; j++) /*열*/
			scanf("%d", &matrix[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int i = 1; i <= n; i++) /*초기화*/
			visit[i] = 0; /*방문안함*/
		dfs(i);
		for (int i = 1; i <= n; i++) /*인접행렬 출력*/
		{
			if (visit[i]) /*방문했다면*/
				printf("%d ", visit[i]);
			else /*방문하지 않았다면*/
				printf("%d ", visit[i]);
		}
		printf("\n");
	}
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