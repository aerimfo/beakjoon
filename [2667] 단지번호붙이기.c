/*[2667] 단지번호붙이기*/
/*https://www.acmicpc.net/problem/2667*/

#include <stdio.h>
char matrix[30][30];
int visit[30][30] = { 0, };
int arr[500];
int n;
int count = 0;
void dfs(int x, int y);

int main()
{
	int temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", matrix[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1' && !visit[i][j])
			{
				dfs(i, j);
				count++;
			}
		}
	}
	for (int i = count - 1; i > 0; i--) /*bubble sort, ★i = count - 1★*/
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
		if (arr[i])
			printf("%d\n", arr[i]);
	return 0;
}

void dfs(int x, int y)
{
	visit[x][y] = 1;
	arr[count] += 1;
	if (x - 1 >= 0 && !visit[x - 1][y] && matrix[x - 1][y] =='1') /*down*/
		dfs(x - 1, y);
	if (x + 1 < n && !visit[x + 1][y] && matrix[x + 1][y] =='1') /*up*/
		dfs(x + 1, y);
	if (y - 1 >= 0 && !visit[x][y - 1] && matrix[x][y - 1] =='1') /*left*/
		dfs(x, y - 1);
	if (y + 1 < n && !visit[x][y + 1] && matrix[x][y + 1] =='1') /*right*/
		dfs(x, y + 1);
}