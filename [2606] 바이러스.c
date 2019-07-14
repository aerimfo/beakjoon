/*[2606] 바이러스*/
/*https://www.acmicpc.net/problem/2606*/
/*dfs가 호출된 횟수 = 바이러스에 감염된 컴퓨터의 수*/

#include <stdio.h>
int matrix[101][101];
int visit[101];
int comn; /*the number of computer*/
int linkedn, count = 0; /*number of connected computer pairs, the number of infected computer*/
void dfs(int v);

int main(void)
{
	int u, v; /*two end points of the trunk line*/
	int cc = 0;/*the number of new dfs invocations, end when count is 2*/
	scanf("%d", &comn);
	scanf("%d", &linkedn);
	for (int i = 0; i < linkedn; i++)
	{
		scanf("%d %d", &u, &v);
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	for(int i=1;i<comn;i++) /*node starts ar 1*/
		if (!visit[1] && (cc < 2))
		{
			dfs(1);
			cc++; /*number of connected components*/
		}
	printf("%d", count - 1); /*except the initial computer*/
	return 0;
}

void dfs(int v)
{
	for (int i = 1; i <= comn; i++)
		if (matrix[v][i] == 1 && !visit[i])
		{
			count++;
			visit[i] = 1; /*visited*/
			dfs(i);
		}
}