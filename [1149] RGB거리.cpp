// RGB 거리
// https://www.acmicpc.net/problem/1149
// dp
// cost[i][j] = j번째 집을 빨강(i=0), 초록(i=1), 파랑(i=2)으로 칠하는 최소 비용
// 인접한 집끼리는 다른 색으로 칠해야 함

#include <iostream>
#include <algorithm> // min
using namespace std;

int main(void)
{
	int n, red, green, blue;
	int cost[3][1001] = { 0, };
	cin >> n;
	cin >> cost[0][0] >> cost[1][0] >> cost[2][0];

	for (int i = 1; i < n; i++) {
		cin >> red >> green >> blue;

		// 현재 집을 빨강색으로 칠하는 경우 -> 이전 집을 초록, 파랑색으로 칠하는 것중 최소 비용과 더해줌
		cost[0][i] = red + min(cost[1][i - 1], cost[2][i - 1]); 

		cost[1][i] = green + min(cost[0][i - 1], cost[2][i - 1]);
		cost[2][i] = blue + min(cost[0][i - 1], cost[1][i - 1]);
	}

	cout << min(cost[0][n - 1], min(cost[1][n - 1], cost[2][n - 1])) << '\n';
}