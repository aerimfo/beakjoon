// [2178] 미로 탐색
// bfs
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

char map[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct MazeInfo {
    int x;
    int y;
    int dis;
};

int solution(int n, int m)
{
    int ans = 1, x, y, dis;
    queue<MazeInfo> q;
    MazeInfo info = {0, 0, 1};
    q.push(info);
    visited[0][0] = true;

    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        dis = q.front().dis;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(map[nx][ny] == '0' || visited[nx][ny] == true) {
                continue;
            }
            if(nx == n-1 && ny == m-1) {
                return dis + 1;
            }
            MazeInfo info = {nx, ny, dis + 1};
            q.push(info);
            visited[nx][ny] = true;
        }
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }
    cout << solution(n, m) << '\n';
}