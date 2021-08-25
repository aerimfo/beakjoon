// [1405] 미친 로봇
// https://www.acmicpc.net/problem/1405
// 브루트포스, dfs, 백트래킹
// 입력을 동, 서, 남, 북으로 받았기 때문에 이동 방향 순서가 중요!

#include <iostream>
using namespace std;

int N;
double prob = 1, ans, cost[4];
bool visited[29][29];
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x, double prob)
{
    if(N == 0) {
        ans += prob;
        return;
    }

    visited[y][x] = true;
    for(int i = 0 ; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        if(visited[ny][nx] == false) { // 방문한 적 없다면
            N--; 
            dfs(ny, nx, prob * cost[i]); // 방문
            N++; 
            visited[ny][nx] = false;
        }
    }
}

int main(void)
{
    cin >> N;
    for(int i = 0 ; i < 4 ; i++) {
        cin >> cost[i]; // 동, 서, 남, 북
        cost[i] *= 0.01;
    }
    dfs(15, 15, 1); // 중심에서 시작
    cout.precision(10);
    cout << fixed << ans << '\n';
}