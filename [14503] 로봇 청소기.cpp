// [14503] 로봇 청소기
// https://www.acmicpc.net/problem/14503

#include <iostream>
using namespace std;

int n, m, r, c, d, map[51][51], visited[51][51];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int nextR, nextC, ans = 0;

bool getBack(int r, int c, int d)
{
    switch (d) {
    case 0:
        nextR = r + 1;
        nextC = c;
        break;
    case 1:
        nextR = r;
        nextC = c - 1;
        break;
    case 2:
        nextR = r - 1;
        nextC = c;
        break;
    case 3:
        nextR = r;
        nextC = c + 1;
        break;
    default:
        break;
    }
   
    if(map[nextR][nextC] == 1) {
        return false;
    }
    else {
        return true;
    }
}

void getNextPos(int r, int c, int d)
{
    switch (d) {
    case 0:
        nextR = r - 1;
        nextC = c;
        break;
    case 1:
        nextR = r;
        nextC = c + 1;
        break;
    case 2:
        nextR = r + 1;
        nextC = c;
        break;
    case 3:
        nextR = r;
        nextC = c - 1;
        break;
    default:
        break;
    }
}

void goAndClean(int r, int c, int d)
{
    bool flag = true;
    // 1번
    if(visited[r][c] == false && map[r][c] == 0) {
        visited[r][c] = true;
        ans++;
    }

    // 2번(c, d)
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i];
        if(visited[nr][nc] == false && map[nr][nc] == 0) {
            flag = false;
            break;
        }
    }

    if(flag == true) { // 네 방향이 모두 벽이거나 이미 청소한 경우
        if(getBack(r, c, d) == false) {
            cout << ans << '\n';
            exit(0);
        }
        goAndClean(nextR, nextC, d);
    }

    // 2번(a, b)
    else {
        int leftDir = d - 1;
        if(leftDir < 0) {
            leftDir = 3;
        }
        getNextPos(r, c, leftDir);
        if(visited[nextR][nextC] == false && map[nextR][nextC] == 0) {
            goAndClean(nextR, nextC, leftDir);
        }
        else {
            goAndClean(r, c, leftDir);
        }
    }
}

void input()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    goAndClean(r, c, d);
}

int main(void)
{
    input();
    cout << ans << '\n';
}