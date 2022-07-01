// [13567] 로봇
// 구현, 시뮬레이션
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
queue<pair<string, int> > q;

void input()
{
    int num;
    string order;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> order >> num;
        q.push(make_pair(order, num));
    }
}

void solution()
{
    int dir = 0; // 동쪽
    int x = 0, y = 0;
    while(!q.empty()) {
        string order = q.front().first;
        int num = q.front().second;
        q.pop();
        if(order == "TURN") {
            if(num == 1) {
                dir--;
                if(dir < 0) dir = 3;
            }
            else {
                dir++;
                if(dir > 3) dir = 0;
            }
        }
        else { // MOVE
            x += num * dx[dir];
            y += num * dy[dir];
            if(x < 0 || x >= m || y < 0 || y >= m) {
                cout << -1 << '\n';
                exit(0);
            }
        }
    }
    cout << y << " " << x << '\n';
}

int main(void)
{
    input();
    solution();

    return 0;
}