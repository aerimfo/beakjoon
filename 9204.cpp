// [9204] 체스
// https://www.acmicpc.net/problem/9204

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int dx[4] = { 1, 1, -1, -1 }, dy[4] = { 1, -1, 1, -1 };
int numS;
char charS;
bool visited[9][9];

void possiblePath(int x, int y)
{
    for(int i = 0 ; i < 4 ; i++) {
        int nx = x, ny = y;
        while(true) {
            nx += dx[i];
            ny += dy[i];
            if(0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                visited[nx][ny] = true;
                continue;
            }
            break;
        }
    }
}

void dfs(int x1, int y1, int x2, int y2)
{
    for(int i = 0 ; i < 4 ; i++) {
        int nx = x1, ny = y1;
        while(true) {
            nx += dx[i];
            ny += dy[i];
            if(0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                if(visited[nx][ny]) {
                    cout << "2 ";
                    cout << (char)(y1 + 'A') << " " << 8 - x1 << " ";
                    cout << (char)(ny + 'A') << " " << 8 - nx << " ";
                    cout << (char)(y2 + 'A') << " " << 8 - x2 << '\n';
                    return;
                }
                continue;
            }
            break;
        }
    }
}

void pathFind(int x1, int y1, int x2, int y2)
{
    if(x1 == x2 &&  y1 == y2) {
        cout << "0 " << (char)(y1 + 'A') << " " << 8 - x1 << '\n';
    }
    else if(abs(x1 - x2) + abs(y1 - y2) % 2 == 1) { // 다른 색 칸 -> 만나지 못함
        cout << "Impossible" << '\n';
    }
    else {
        possiblePath(x2, y2);
        if(visited[x1][y1]) { // 한 번에 갈 수 있음
            cout << "1 ";
            cout << (char)(y1 + 'A') << " " << 8 - x1 << " ";
            cout << (char)(y2 + 'A') << " " << 8 - x2 << '\n';
            return;
        }
        else {
            dfs(x1, y1, x2, y2);
        }
    }
}

void input()
{
    int t, numF;
    char charF;
    cin >> t;
    while(t--) {
        cin >> charF >> numF >> charS >> numS;
        pathFind(8 - numF, charF - 'A', 8 - numS, charS - 'A');
        memset(visited, false, sizeof(visited));
    }
}

int main(void)
{
    input();
}