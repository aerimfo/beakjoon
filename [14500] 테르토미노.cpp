// [14500] 테트로미노
// https://www.acmicpc.net/problem/14500
// 브루트포스
// 범위는 n, m보다 작아야 하지만 0보다는 크거나 같아야 함에 주의

#include <iostream>
using namespace std;

int n, m, ans = 0;
int map[501][501];

void tet(int x, int y)
{
    // -
    if(y + 3 < m) {
        if(ans < map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3]) {
            ans = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3];
        }
    }

    // ㅣ
    if(x + 3 < n) {
        if(ans < map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y];
        }
    }

    // ㅁ
    if(x + 1 < n && y + 1 < m) {
        if(ans < map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1]) {
            ans = map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1];   
        }
    }

    // ⎿
    if(x + 2 < n && y + 1 < m) {
        if(ans < map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y + 1]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y + 1];
        }
    }

    // ⏌
    if(x + 2 < n && 0 < y - 1) {
        if(ans < map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y - 1]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y - 1];
        }
    }

    // ⌐, ⌙
    if(x + 1 < n && y + 2 < m) {
        if(ans < map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y]) {
            ans = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y];
        }
        if(ans < map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2];
        }
    }

    // ⏋, ⎾
    if(x + 2 < n && y + 1 < m) {
        if(ans < map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1]) {
            ans = map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1];
        }
        if(ans < map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 2][y]) {
            ans = map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 2][y];
        }
    }

    if(x + 1 < n && 0 <= y - 2) {
        if(ans < map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y - 2]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y - 2];
        }
        if(ans < map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y - 2]) {
            ans = map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y - 2];
        }
    }

    // 연두색
    if(0 <= x - 1 && x + 1 < n && y + 1 < m) {
        if(ans < map[x][y] + map[x - 1][y] + map[x][y + 1] + map[x + 1][y + 1]) {
            ans = map[x][y] + map[x - 1][y] + map[x][y + 1] + map[x + 1][y + 1];
        }
        if(ans < map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x - 1][y + 1]) {
            ans = map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x - 1][y + 1];   
        }
    }

    if(x + 1 < n && 0 <= y - 1 && y - 1 < m) {
        if(ans < map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y - 1]) {
            ans = map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y - 1];
        }
        if(ans < map[x][y] + map[x][y - 1] + map[x + 1][y] + map[x + 1][y + 1]) {
            ans = map[x][y] + map[x][y - 1] + map[x + 1][y] + map[x + 1][y + 1];
        }
    }

    // 분홍색
    if(x + 1 < n && y + 2 < m) {
        if(ans < map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x][y + 2]) {
            ans = map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x][y + 2];
        }
    }

    if(x + 2 < n && 0 <= y - 1) {
        if(ans < map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 2][y]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 2][y];
        }
    }

    if(0 <= x - 1 && y + 2 < m) {
        if(ans < map[x][y] + map[x][y + 1] + map[x - 1][y + 1] + map[x][y + 2]) {
            ans = map[x][y] + map[x][y + 1] + map[x - 1][y + 1] + map[x][y + 2];
        }
    }

    if(x + 2 < n && y + 1 < m) {
        if(ans < map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]) {
            ans = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            tet(i, j);
        }
    }

    cout << ans << '\n';
    return 0;
}