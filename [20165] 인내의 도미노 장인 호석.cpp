// [20165] 인내의 도미노 장인 호석
// 구현, 시뮬레이션
#include <iostream>
#include <queue>
using namespace std;

bool fallen[101][101];
int n, m, r, x, y, ans = 0;
int map[101][101], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct Info {
    int x;
    int y;
    int h;
    int d;
};


int makeDir(char D)
{
    if(D == 'N') return 0;
    else if(D == 'E') return 1;
    else if(D == 'S') return 2;
    else return 3;
}

void startDomino(char D)
{
    int d = makeDir(D);
    queue<Info> q;
    Info info = {x, y, map[x][y], d};
    q.push(info);

    // 나 자신도 넘어짐
    if(fallen[x][y] == false) {
        fallen[x][y] = true;
        ans++; 
    }

    while(!q.empty()) {
        Info cur = q.front();
        q.pop();
        int nx = cur.x, ny = cur.y;
        for(int i = 0; i < (cur.h-1); i++) {
            nx += dx[cur.d];
            ny += dy[cur.d];
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if(fallen[nx][ny] == false) {
                fallen[nx][ny] = true;
                Info info = {nx, ny, map[nx][ny], cur.d};
                q.push(info);
                ans++;
            }
        }
    }
}

void printAns()
{
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(fallen[i][j] == true) cout << "F ";
            else cout << "S ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char d;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < r; i++) {
        cin >> x >> y >> d; // 공격수
        startDomino(d);
        cin >> x >> y; // 수비수
        fallen[x][y] = false;
    }

    printAns();
    return 0;
}