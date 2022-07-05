// [1103] 게임
// 이분 탐색
// dp[x][y] = (x, y)에서의 최대 이동 횟수
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, dp[51][51];
char map[51][51];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool visited[51][51];

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }
}

int dfs(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == 'H') {
        return 0;
    }
	if(visited[x][y] == true) {
		cout << -1 << '\n';
		exit(0);
	}
	if(dp[x][y] != -1) {
		return dp[x][y];
    }

    int length = map[x][y] - '0'; // 움직여야 할 칸 수
	dp[x][y] = 0;
    visited[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + length * dx[i];
		int ny = y + length * dy[i];
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visited[x][y] = false;
	return dp[x][y];
}

int main(void)
{
    input();
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';
}