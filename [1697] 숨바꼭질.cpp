/*[1697] ¼û¹Ù²ÀÁú*/
/*https://www.acmicpc.net/problem/1697*/
/*BFS*/

#include <iostream>
#include <queue>
using namespace std;

int visited[100001] = { 0, };
int bfs(int x, int y);

int main(void)
{
	int n, k; //location of subin and sister
	cin >> n >> k;
	cout << bfs(n, k);
}

int bfs(int x, int y)
{
	int time = 0; //the fastest time to find sister
	queue<int> q;
	q.push(x);
	
	while (1)
	{
		int size = q.size(); //if not equal to k, size increases
		for (int i = 0; i < size; i++)
		{
			x = q.front();
			q.pop();
			if (x == y)
			{
				return time;
			}
			if (0 <= x - 1 && visited[x - 1] == 0)
			{
				q.push(x - 1);
				visited[x - 1] = 1;
			}
			if (x + 1 <= 100000 && visited[x + 1] == 0)
			{
				q.push(x + 1);
				visited[x + 1] = 1;
			}
			if (2 * x <= 100000 && visited[2 * x] == 0)
			{
				q.push(2 * x);
				visited[2 * x] = 1;
			}
		}
		time++;
	}
}