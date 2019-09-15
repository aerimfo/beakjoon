/*[2583] 영역구하기*/
/*https://www.acmicpc.net/problem/2583*/
/*BFS*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n; //height, width
int cnt = 0; //the number of connected components
int maze[101][101] = { 0, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int>area;
void bfs(int x, int y);

int main(void)
{
	int k; //the number of squares
	int x1, x2, y1, y2;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = m - 1 - y1; j >= m - y2; j--) //row
		{
			for (int k = x2 - 1; k >= x1; k--) //column
			{
				if(maze[j][k]==0) //empty
					maze[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 0) //empty
				bfs(i, j);
		}
	}
	cout << cnt << endl;
	sort(area.begin(), area.end());
	for (int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}
	return 0;
}

void bfs(int x, int y)
{
	int sum = 0; //area of connected component
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	maze[x][y] = 2; //visited

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		sum++;
		for (int i = 0; i < 4; i++) //east, north, west, south
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];

			if (0 <= nextx && nextx < m && 0 <= nexty && nexty < n && maze[nextx][nexty] == 0)
			{
				maze[nextx][nexty] = 2;
				q.push(make_pair(nextx, nexty));
			}
		}
	}
	area.push_back(sum);
	cnt++; //bfs end
}