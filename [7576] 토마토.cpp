#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> >tomatos;

int box[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
int total = 0;
int solve();

int main()
{
	/*큐에는 익은 토마토의 위치가 들어가있음 -> (x, y)쌍*/
	cin >> n >> m;
	for (int i = 0; i < m; i++) /*m먼저 돌기!!*/
		for (int j = 0; j < n; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1) /*익은 토마토*/
				tomatos.push(make_pair(i, j));
			else if (box[i][j] == -1) /*토마토 안들어있음*/
				total++;
		}
	cout << solve();
	return 0;
}

int solve()
{
	pair<int, int>now; /*내가 지금 있는 곳*/
	int size = 0, days = 0;
	int nextx, nexty;
	while (!tomatos.empty())
	{
		size = tomatos.size(); /*새롭게 익은 토마토의 개수*/
		total += size;
		if (total == n * m) /*모든 토마토가 익었다!*/
			return days;
		for (int i = 0; i < size; i++)
		{
			now = tomatos.front();
			tomatos.pop();
			for (int j = 0; j < 4; j++) /*dx, dy 사용해서 nextx, nexty좌표 구하기*/
			{
				nextx = now.first + dx[j];
				nexty = now.second + dy[j];
				if (nextx >= 0 && nextx < m&&nexty >= 0 && nexty < n && !box[nextx][nexty])
				{
					box[nextx][nexty] = 1;/*익게 해줌*/
					tomatos.push(make_pair(nextx, nexty));
				}
			}
		}
		days++;
	}
	return -1;
}