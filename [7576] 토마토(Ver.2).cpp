// [7576] 토마토
// bfs
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int map[1001][1001];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct TomatoInfo {
    int x;
    int y;
    int day;
};
queue<TomatoInfo> q;

bool isAllRipe(int n, int m)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void solution(int n, int m)
{
    int maxDay = q.front().day;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int day = q.front().day;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(map[nx][ny] == 1 || map[nx][ny] == -1) {
                continue;
            }
            map[nx][ny] = 1;
            TomatoInfo info = {nx, ny, day + 1};
            q.push(info);
            if(day + 1 > maxDay) {
                maxDay = day + 1;
            }
        }
    }
    if(isAllRipe(n, m)) {
        cout << maxDay << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                TomatoInfo info = {i, j, 0};
                q.push(info);
            }
        }
    }
    solution(n, m);
}