// [2468] 안전 영역
// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <cstring>
using namespace std;

int n, heights[101][101], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool safeZone[101][101];
int minHeight = 101, maxHeight = 0;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> heights[i][j];
            if(heights[i][j] < minHeight) {
                minHeight = heights[i][j];
            }
            if(heights[i][j] > maxHeight) {
                maxHeight = heights[i][j];
            }
        }
    }
}

void makeRain(int height)
{
    memset(safeZone, true, sizeof(safeZone));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(heights[i][j] <= height) {
                safeZone[i][j] = false;
            }       
        }
    }
}

void dfs(int x, int y)
{
    safeZone[x][y] = false;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }
        if(safeZone[nx][ny] == true) {
            dfs(nx, ny);
        }
    }
}

int getSafeZone()
{
    int safeZoneNum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(safeZone[i][j] == true) {
                dfs(i, j);
                safeZoneNum++;
            }
        }
    }

    return safeZoneNum;
}

void solve()
{
    int ans = 0;
    for(int i = minHeight-1; i <= maxHeight; i++) {
        makeRain(i);
        int result = getSafeZone();
        if(result > ans) {
            ans = result;
        }
    }

    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}