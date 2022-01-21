// [17086] 아기 상어 2
// https://www.acmicpc.net/problem/17086

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, space[51][51];

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> space[i][j];
        }
    }
}

int bfs(int sx, int sy)
{
    bool visited[51][51] = {false, };
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
    queue <pair<pair<int, int>, int> > q;

    visited[sx][sy] = true;
    q.push(make_pair(make_pair(sx, sy), 0));

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        if(space[x][y] == 1) {
            return dis;
        }
        for(int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if(visited[nextX][nextY] == false) {
                    int nextDistance = dis + 1;
                    q.push(make_pair(make_pair(nextX, nextY), nextDistance));
                    visited[nextX][nextY] = true;
                }
            }
        }
    }
}

int getMinSafeDistance()
{
    int maxDistance = 0, dis;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(space[i][j] == 0) {
                dis = bfs(i, j);
                if(dis > maxDistance) {
                    maxDistance = dis;
                }
            }
        }
    }

    return maxDistance;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << getMinSafeDistance() << '\n';
}