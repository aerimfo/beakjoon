#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2188

using namespace std;

/*count[0] = -1의 개수
  count[1] = 0의 개수
  count[2] = 1의 개수*/

vector<int>list[MAX];
bool check(int x, int y, int n);
void solve(int x, int y, int n);
int n;
int cnt[3] = { 0 };

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) /*행렬 입력받기*/
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			list[j].push_back(num);
		}
	}
	check(0, 0, n);
	solve(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;
}
bool check(int x, int y, int n) /*check if same or not*/
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (list[i][j] != list[x][y])
				return false;
	return true;
}

void solve(int x, int y, int n) 
{
	int m;
	if (check(x, y, n) == true)
	{
		cnt[list[x][y] + 1] += 1;
		return;
	}
	else
	{
		int m = n / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				solve(x + i * m, y + j * m, m);
	}
	/*노가다*/
	/*else
	{
		m = n / 3;
		solve(x, y, m);
		solve(x, y + m, m);
		solve(x, y + 2 * m, m);
		solve(x + m, y, m);
		solve(x + m, y + m, m);
		solve(x + m, y + 2 * m, m);
		solve(x + 2 * m, y, m);
		solve(x + 2 * m, y + m, m);
		solve(x + 2 * m, y + 2 * m, m);
	}*/
}