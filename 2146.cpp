// [2146] 다리 만들기
// https://www.acmicpc.net/problem/2146
// 0인 점에서 BFS로 이동하다가 1 만날때까지 이동횟수 카운트, 정답 가능 리스트에 저장하고 정렬 후 제일 첫번째 원소 출력
// 모든 0인점에서 시작하는 것이 아님, 섬에 인접한 0에서만 탐색 시작

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int island[101][101];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[101][101];
vector <int> list;

void bfs(int x, int y) 
{
    cout << "왜 안돼ㅜ" << '\n';
    int cnt = 1;
    queue<pair<int, int> >q; 
    q.push(make_pair(x, y)); 
    visited[x][y] = 1;
    while (!q.empty()) { 
        x = q.front().first; 
        y = q.front().second;
        cout << "x = " << x << " y = " << y << '\n'; 
        q.pop(); 
        for (int i = 0; i < 4; i++) { 
            int nextx = x + dx[i]; 
            int nexty = y + dy[i]; 
            if (0 <= nextx && nextx < n && 0 <= nexty && nexty < n) { 
                if (visited[nextx][nexty] == 0 && island[nextx][nexty] == 0) { 
                    visited[nextx][nexty] = true;
                    cnt++;
                    q.push(make_pair(nextx, nexty)); 
                } 
                else if(island[nextx][nexty] == 1) {
                    list.push_back(cnt);
                    cnt = 0;
                }
            } 
        } 
    } 
}

void input()
{   
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> island[i][j];
        }
    }
}

int main(void)
{
    input();
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(island[i][j] == 0 && (island[i][j - 1] == 1 || island[i][j + 1] == 1)) { // 바다라면
                memset(visited, false, sizeof(visited));
                bfs(i, j);
            }
        }
    }

    sort(list.begin(), list.end());
    cout << list[0] << '\n';

    return 0;
}