/*[4963] 섬의 개수*/
/*https://www.acmicpc.net/problem/4963*/
/*graph algorithm*/
/*1 == land, 0 == sea*/

#include <iostream>
#include <cstdio>
using namespace std;
int visited[50][50] = { 0, };
int map[50][50];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int w, h, cnt = 0; /*width, height, the number of connected components*/
void dfs(int, int);

int main(void)
{
	while (1)
	{
		cin >> w >> h;
		if ((w == 0) && (h == 0))
			return 0;
		else
			for (int i = 0; i < h; i++) /*input map*/
				for (int j = 0; j < w; j++)
					scanf("%d", &map[i][j]);

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == 0 && map[i][j] == 1) /*unvisited land*/
				{
					dfs(i, j);
					cnt++;
				}
			}
		cout << cnt << endl;

		/*initialization*/
		cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				map[i][j] = 0;
				visited[i][j] = 0;
			}
	}
}

void dfs(int x, int y)
{
	visited[x][y] = 1;/*visited*/
	int nx, ny;
	for (int i = 0; i < 8; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ((nx >= h) || (nx < 0) || ny >= w || ny < 0)
			continue;
		if (visited[nx][ny] == 0 && map[nx][ny] == 1)
			dfs(nx, ny);
	}
}