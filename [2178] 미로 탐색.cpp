/*[2178] ¹Ì·Î Å½»ö*/
/*https://www.acmicpc.net/problem/2178*/
/*BFS*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int visit[101][101] = { 0, };
int maze[101][101] = { 0, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void bfs(int x, int y);

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) /*input maze, start with (1, 1)*/
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &maze[i][j]); /*¡Ú1d!!¡Ú*/
		}
	}
	bfs(1, 1);
	cout << visit[n][m] << endl;
}

void bfs(int x, int y)
{
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	visit[x][y] = 1; /*visited*/

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) /*east, north, west, south*/
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 < nx && nx <= n && 0 < ny && ny <= m)
			{
				if (visit[nx][ny] == 0 && maze[nx][ny] == 1) /*if not visited and can pass*/
				{
					q.push(make_pair(nx, ny));
					visit[nx][ny] = visit[x][y] + 1;
				}
				else if (visit[nx][ny] == 0) /*not visited and cannot pass*/
				{
					visit[nx][ny] = -1;
				}

			}
		}
	}
}