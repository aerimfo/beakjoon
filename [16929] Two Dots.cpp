// [16929] Two Dots
// https://www.acmicpc.net/problem/16929
// dfs

#include <iostream>
#include <cstring>
using namespace std;

char game[51][51];
bool visited[51][51];
int n, m,sx,sy;
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 };

void input()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> game[i][j];
        }
    }
}

void dfs(int x, int y, int cnt)
{
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (visited[nx][ny] == false) {
				if (game[nx][ny] == game[sx][sy]) {
					visited[nx][ny] = true;
					dfs(nx, ny, cnt + 1); 
				}
			}
			else {
				if (cnt >= 4 && sx == nx && sy == ny) {
					cout << "Yes" << '\n';
                    exit(0);
				}
			}
		}
	}
}

int main()
{
    input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			sx = i; sy = j;
			visited[sx][sy] = true;
			dfs(i, j, 1);
		}
	}
	cout << "No" << endl;
	return 0;
}