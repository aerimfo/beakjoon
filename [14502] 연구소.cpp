// [14502] 연구소
// https://www.acmicpc.net/problem/14502
// bfs , 브루트포스

#include <iostream>
#include <queue>
using namespace std;

int n, m, ans = 0; // 지도의 세로, 가로 크기, 정답
int map[9][9], tmp[9][9], afterVirus[9][9];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

void copyMap(int a[9][9], int b[9][9])
{
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            b[i][j] = a[i][j];
        }
    }
}

void safeArea()
{
    int cnt = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(afterVirus[i][j] == 0) { // 빈칸이라면
                cnt++;
            }
        }
    }
    ans = (ans > cnt ? ans : cnt); // 가장 큰 안전영역의 개수를 ans에 저장
}

void spreadVirus()
{
    copyMap(tmp, afterVirus); // 3개의 벽을 추가로 세운 상태를 복사

    // 바이러스의 위치 저장
    queue<pair<int, int> > virus;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(afterVirus[i][j] == 2) {
                virus.push(make_pair(i, j));
            }
        }
    }

    // 바이러스 확산 시키기
    while(!virus.empty()) {
        int x = virus.front().first;
        int y = virus.front().second;
        virus.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int nextx = x + dx[i]; 
            int nexty = y + dy[i];

            if(0 <= nextx && nextx < n && 0 <= nexty && nexty < m) { // 범위 안에 있고
                if(afterVirus[nextx][nexty] == 0) { // 빈칸이라면
                    afterVirus[nextx][nexty] = 2; // 바이러스 감염
                    virus.push(make_pair(nextx, nexty)); // 바이러스 위치를 저장한 큐에 추가
                }
            }
        }
    }

    safeArea(); // 안전영역 구하기
}

void makeWall(int cnt)
{
    // 벽 3개를 모두 세운 경우
    if(cnt == 3) {
        spreadVirus(); // 바이러스 확산
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(tmp[i][j] == 0) { // 빈칸인 경우
                tmp[i][j] = 1; // 벽을 세움
                makeWall(cnt+1);
                tmp[i][j] = 0; // 벽을 없앰
            }
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
            if(map[i][j] == 0) {
                copyMap(map, tmp);
                tmp[i][j] = 1; // 벽을 세움
                makeWall(1);
                tmp[i][j] = 0; // 벽을 없앰
            }
        }
    }

    cout << ans << '\n';
    return 0;
}