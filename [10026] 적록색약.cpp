/*[10026] 적록색약*/
/*https://www.acmicpc.net/problem/10026*/
/*BFS*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
char map[100][100];
int visited[100][100] = { 0, };
int cnt = 0; //the number of connected components
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
void bfs(int x, int y);
void NotColorBlind(void);
void ColorBlind(void);

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	NotColorBlind();
	ColorBlind();
}

void NotColorBlind(void)
{
	//not red-green blindness
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'R')
				map[i][j] = 0;
			else if (map[i][j] == 'G')
				map[i][j] = 1;
			else if (map[i][j] == 'B')
				map[i][j] = 2;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0) //not visited
				bfs(i, j);
		}
	}
	cout << cnt << " ";

	//initialization
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		memset(visited[i], 0, sizeof(int)*n);
	}
}

void ColorBlind(void)
{
	//red-green blindness
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
				map[i][j] = 0;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0) //not visited
				bfs(i, j);
		}
	}
	cout << cnt;
}

void bfs(int x, int y)
{
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	visited[x][y] = 1; //visited

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) //east, north, west, south
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];

			if (0 <= nextx && nextx < n && 0 <= nexty && nexty < n)
			{
				if (visited[nextx][nexty] == 0 && map[nextx][nexty] == map[x][y])
				{
					visited[nextx][nexty] = 1;
					q.push(make_pair(nextx, nexty));
				}
			}
		}
	}
	cnt++; //bfs end
}
