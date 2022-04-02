// [23289] 온풍기 안녕!
// https://www.acmicpc.net/problem/23289
// 구현, 시뮬레이션

#include <iostream> 
#include <cstring>
#include <queue>
using namespace std;

bool rightWall[21][21], topWall[21][21];
int r, c, k, chocolate = 0, room[21][21], temperature[21][21], tmp[21][21];
int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};
int hdx[5][3] = {{0, 0, 0}, {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
int hdy[5][3] = {{0, 0, 0}, {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};
struct tempInfo
{
    int x;
    int y;
    int level;
};


void input()
{
    int w, x, y, t;
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> room[i][j];
        }
    }
    cin >> w;
    for(int i = 0; i < w; i++) {
        cin >> x >> y >> t;
        if(t == 0) {
            topWall[x][y] = true;
        }
        else {
            rightWall[x][y] = true;
        }
    }
}

bool isBiggerThanK()
{
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(room[i][j] == 5) {
                if(temperature[i][j] >= k) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isNoWall(int x, int y, int dir, int idx)
{
    switch (dir) {
    case 1:
        switch (idx) {
        case 0:
            if(topWall[x][y] == false && rightWall[x-1][y] == false) return true;
            else return false;
        case 1:
            if(rightWall[x][y] == false) return true;
            return false;
        case 2:
            if(topWall[x+1][y] == false && rightWall[x+1][y] == false) return true;
            return false;
        default:
            break;
        }
    case 2:
        switch (idx) {
        case 0:
            if(topWall[x][y] == false && rightWall[x-1][y-1] == false) return true;
            else return false;
        case 1:
            if(rightWall[x][y-1] == false) return true;
            return false;
        case 2:
            if(topWall[x+1][y] == false && rightWall[x+1][y-1] == false) return true;
            return false;
        default:
            break;
        }
    case 3:
        switch (idx) {
        case 0:
            if(topWall[x][y-1] == false && rightWall[x][y-1] == false) return true;
            else return false;
        case 1:
            if(topWall[x][y] == false) return true;
            return false;
        case 2:
            if(topWall[x][y+1] == false && rightWall[x][y] == false) return true;
            return false;
        default:
            break;
        }
    case 4:
        switch (idx) {
        case 0:
            if(topWall[x+1][y-1] == false && rightWall[x][y-1] == false) return true;
            else return false;
        case 1:
            if(topWall[x+1][y] == false) return true;
            return false;
        case 2:
            if(topWall[x+1][y+1] == false && rightWall[x][y] == false) return true;
            return false;
        default:
            break;
        }
    }
}

void startHeater(int x, int y)
{
    bool isChanged[21][21] = {false, };
    int dir = room[x][y];
    queue<tempInfo> q;
    x += hdx[dir][1], y += hdy[dir][1];
    tempInfo tempinfo = {x, y, 5};
    q.push(tempinfo);
    temperature[x][y] += 5;
    isChanged[x][y] = true;

    while(!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int level = q.front().level;
        q.pop();
        if(level == 1) continue;
        for(int i = 0; i < 3; i++) {
            int nx = cx + hdx[dir][i];
            int ny = cy + hdy[dir][i];
            if(nx < 1 || nx > r || ny < 1 || ny > c) {
                continue;
            }
            if(isChanged[nx][ny] == false && isNoWall(cx, cy, dir, i) == true) {
                isChanged[nx][ny] = true;
                tempInfo tempinfo = {nx, ny, level - 1};
                q.push(tempinfo);
                temperature[nx][ny] += (level - 1);
            }
        }
    }
}

void increaseTemparature()
{
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(1 <= room[i][j] && room[i][j] <= 4) {
                startHeater(i, j);
            }
        }
    }
}

void adjustTemperature()
{
    int compareDir[2] = {1, 4};
    memcpy(tmp, temperature, sizeof(temperature));
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            for(int k = 0; k < 2; k++) {
                int dir = compareDir[k];
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 1 || nx > r || ny < 1 || ny > c) {
                    continue;
                }
                if(isNoWall(i, j, dir, 1) == false) { // 실수한 부분(dir을 넘겨야 하는데 k를 넘김..)
                    continue;
                }
                int biggerX = i > nx ? i : nx;
                int smallerX = i < nx ? i : nx;
                int biggerY = j > ny ? j : ny;
                int smallerY = j < ny ? j : ny;
                int gap = (temperature[biggerX][biggerY] - temperature[smallerX][smallerY]) / 4;
                tmp[biggerX][biggerY] -= gap;
                tmp[smallerX][smallerY] += gap;
            }
        }
    }
}

void decreaseTemperature()
{
    // 테두리만 체크
    for(int i = 1; i <= r; i++) {
        if(tmp[i][1] >= 1) {
            tmp[i][1]--;
        }
        if(tmp[i][c] >= 1) {
            tmp[i][c]--;
        }
    }
    for(int i = 2; i < c; i++) {
        if(tmp[1][i] >= 1) {
            tmp[1][i]--;
        }
        if(tmp[r][i] >= 1) {
            tmp[r][i]--;
        }
    }
    memcpy(temperature, tmp, sizeof(tmp));
}

void solve()
{
    while(true) {
        if(isBiggerThanK() == true) {
            break;
        }
        else {
            increaseTemparature();
            adjustTemperature();
            decreaseTemperature();
            chocolate++;
            if(chocolate > 100) {
                cout << 101 << '\n';
                return;
            }
        }
    }
    cout << chocolate << '\n';
}

int main(void)
{
    input();
    solve();
}