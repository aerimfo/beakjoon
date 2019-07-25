#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 65

using namespace std;

vector<char>list[MAX];
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
			char num;
			cin >> num;
			list[i].push_back(num);
		}
	}
	check(0, 0, n);
	solve(0, 0, n);
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
		cout << list[x][y];
		return;
	}
	else
	{
		cout << '(';
		int m = n / 2;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				solve(x + i * m, y + j * m, m);
		}
		cout << ')';
	}
}