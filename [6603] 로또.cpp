//[6603] ·Î¶Ç
//https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> visited;
void dfs(int, int);

int main(void)
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		arr = vector<int>(n, 0);
		visited = vector<int>(n, 0);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		dfs(0, 0);
		cout << endl;
	}
}

void dfs(int x, int len)
{
	if (len == 6)
	{
		for (int i = 0; i < n; i++)
			if (visited[i])
				cout << arr[i] << " ";
		cout << endl;
		return;
	}

	if (n - x < 6 - len)
		return;

	visited[x]++;
	dfs(x + 1, len + 1);

	visited[x]--;
	dfs(x + 1, len);
}