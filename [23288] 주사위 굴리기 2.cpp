// [23288] 주사위 굴리기 2
// https://www.acmicpc.net/problem/23288

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[21][21];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int n, m, k, board[21][21], movingSpace = 0, ans = 0;
int diceX = 1, diceY = 1, floor = 6, east = 3, south = 5, dir = 3;

void input()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
}

void rollDice(int dir)
{   
    int tmp = floor;
    switch (dir)
    {
    case 0:
        floor = 7 - south;
        south = tmp;
        break;
    case 1:
        floor = 7 - east;
        east = tmp;
        break;
    case 2:
        floor = south;
        south = 7 - tmp;
        break;
    case 3: 
        floor = east;
        east = 7 - tmp;
        break;
    default:
        break;
    }
}

void checkRangeAndRollDice()
{
    int nx = diceX + dx[dir];
    int ny = diceY + dy[dir];
    if(nx < 1 || nx > n || ny < 1 || ny > m) {
        // 방향 반대로
        if(dir == 2 || dir == 3) dir -= 2;
        else dir += 2;
        nx = diceX + dx[dir]; ny = diceY + dy[dir];
        rollDice(dir);
    }
    else {
        rollDice(dir);
    }
    diceX = nx; diceY = ny;
}

void bfs()
{
    queue<pair<int, int> > q;
    visited[diceX][diceY] = true;
    q.push(make_pair(diceX, diceY));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if(visited[nx][ny] == false && board[nx][ny] == board[diceX][diceY]) {
                movingSpace++;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }   
}

void getScore()
{
    movingSpace = 1;
    memset(visited, false, sizeof(visited));
    bfs();
    ans += board[diceX][diceY] * movingSpace;
}

void setDirection()
{
    if(floor > board[diceX][diceY]) {
        dir--;
        if(dir == -1) dir = 3;
    }
    else if(floor < board[diceX][diceY]) {
        dir++;
        if(dir == 4) dir = 0;
    }
}

void go()
{
    checkRangeAndRollDice();
    getScore();
    setDirection();
}

int main(void)
{
    input();
    while(k--) {
        go();
    }
    cout << ans << '\n';
}