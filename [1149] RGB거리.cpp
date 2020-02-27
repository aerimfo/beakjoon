//RGB°Å¸®
//https://www.acmicpc.net/problem/1149
//dp

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, red, green, blue;
	int cost[3][1001] = { 0, };
	cin >> n;
	cin >> cost[0][0] >> cost[1][0] >> cost[2][0];
	for (int i = 1; i < n; i++)
	{
		cin >> red >> green >> blue;

		cost[0][i] = red + min(cost[1][i - 1], cost[2][i - 1]);
		cost[1][i] = green + min(cost[0][i - 1], cost[2][i - 1]);
		cost[2][i] = blue + min(cost[0][i - 1], cost[1][i - 1]);
	}
	cout << min(cost[0][n - 1], min(cost[1][n - 1], cost[2][n - 1])) << endl;
}