/*[13567] 로봇*/
/*https://www.acmicpc.net/problem/13567*/

#include <iostream>
#include <string>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main(void)
{
	//dir 0, 1, 2, 3 = 동, 서, 남, 북
	int m, n, x = 0, y = 0, dir = 0;
	int num;
	int check = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		string order;
		cin >> order >> num;
		if (order == "MOVE" && check == 0) //범위 안에 있다면
		{
			for (int j = 0; j < num; j++)
			{
				x += dy[dir];
				y += dx[dir];
				if (x < 0 || x >= n || y < 0 || y >= n)
				{
					check = -1; //out of boundary
				}
			}
		}
		else if (order == "TURN")
		{
			if (num == 0) //동쪽
			{
				dir = (dir + 4 - 1) % 4;
			}
			else
				dir = (dir + 1) % 4;
		}
	}
	if (check == 0)
		cout << y << " " << x;
	else
		cout << check;
}