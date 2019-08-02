/*[1012] ¿Ø±‚≥Û πË√ﬂ*/
/*https://www.acmicpc.net/problem/1012*/
#include <stdio.h>

int matrix[51][51] = { 0, }, width[51], height[51];
int visit[51][51] = { 0, };
int i;
void dfs(int x, int y);

int main(void)
{
	int spot[51], arr[2501];
	int t, count; /*the number of test cases, number of connected components*/
	int x, y;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		count = 0;
		scanf("%d %d %d", &width[i], &height[i], &spot[i]);
		for (int j = 0; j < spot[i]; j++)
		{
			scanf("%d %d", &x, &y);
			matrix[y][x] = 1;
		}
		for (int j = 0; j < height[i]; j++)
			for (int k = 0; k < width[i]; k++)
				if (matrix[j][k] == 1 & !visit[j][k])
				{
					dfs(j, k);
					count++;
				}
		/*initialization*/
		arr[i] = count;
		for (int j = 0; j < 51; j++)
			for (int k = 0; k < 51; k++)
			{
				matrix[j][k] = 0;
				visit[j][k] = 0;
			}
	}
	for (int i = 0; i < t; i++)
		printf("%d\n", arr[i]);
}

void dfs(int x, int y)
{
	visit[x][y] = 1;
	if (x - 1 >= 0 && !visit[x - 1][y] && matrix[x - 1][y] == 1)
		dfs(x - 1, y);
	if (x + 1 < height[i] && !visit[x + 1][y] && matrix[x + 1][y] == 1)
		dfs(x + 1, y);
	if (y - 1 >= 0 && !visit[x][y - 1] && matrix[x][y - 1] == 1)
		dfs(x, y - 1);
	if (y + 1 < width[i] && !visit[x][y + 1] && matrix[x][y + 1] == 1)
		dfs(x, y + 1);
}