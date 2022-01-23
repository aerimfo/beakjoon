// [1743] 음식물 피하기
// https://www.acmicpc.net/problem/1743

#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool trash[101][101], visited[101][101];
queue <pair<int, int> > q;

void input()
{
    int x, y;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        trash[x][y] = true;
    }
}

int bfs(int x, int y)
{
    int sx, sy, size = 1;

    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        sx = q.front().first;
        sy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(sx + dx[i] >= 1 && sx + dx[i] <= n && sy + dy[i] >= 1 && sy + dy[i] <= m) {
                if(trash[sx + dx[i]][sy + dy[i]] == true && visited[sx + dx[i]][sy + dy[i]] == false) {
                    q.push(make_pair(sx + dx[i], sy + dy[i]));
                    visited[sx + dx[i]][sy + dy[i]] = true;
                    size++;
                }
            }
        }
    }

    return size;
}

int main(void)
{
    int maxSize = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(trash[i][j] == true && visited[i][j] == false) {
                int size = bfs(i, j);
                if(size > maxSize) {
                    maxSize = size;
                }
            }
        }
    }

    cout << maxSize << '\n';
}