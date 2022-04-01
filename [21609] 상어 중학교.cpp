// [21609] 상어 중학교
// https://www.acmicpc.net/problem/21609
// 구현, 시뮬레이션, dfs, bfs

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;

bool visited[21][21];
int n, m, ans = 0, map[21][21], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int maxBlockGroupSize = 0, maxRainbowBlocks = 0, maxGroupRow = 0, maxGroupColumn = 0;
vector<pair<int, int> > groupVec, tmpVec;

void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
}

int bfs(int x, int y)
{
    int rainbowBlocks = 0;
    queue<pair<int, int> > q;
    
    tmpVec.clear();
    q.push(make_pair(x, y));
    tmpVec.push_back(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }
            if(visited[nx][ny] == false) {
                if(map[nx][ny] == map[x][y] || map[nx][ny] == 0) {
                    if(map[nx][ny] == 0) {
                        rainbowBlocks++;
                    }
                    visited[nx][ny] = true;
                    tmpVec.push_back(make_pair(nx, ny));
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return rainbowBlocks;
}

void resetVisitedMap()
{
    // 무지개 블록은 다시 방문할 수 있도록 처리
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == 0) {
                visited[i][j] = false;
            }
        }
    }
}

bool checkMaxGroup(int r, int c, int rainbowBlocks)
{
    if(tmpVec.size() > maxBlockGroupSize) {
        return true;
    }
    else if(tmpVec.size() == maxBlockGroupSize) {
        if(rainbowBlocks > maxRainbowBlocks) {
            return true;
        }
        else if(rainbowBlocks == maxRainbowBlocks) {
            if(r > maxGroupRow) {
                return true;
            }
            else if(r == maxGroupRow) {
                if(c > maxGroupColumn) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool findMaxBlockGroup()
{
    bool isMax = false, isGroup = false;
    int rainbowBlocks = 0;
    groupVec.clear(); 
    maxBlockGroupSize = 0; maxGroupRow = 0, maxGroupColumn = 0; maxRainbowBlocks = 0;
    memset(visited, false, sizeof(visited));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            isMax = false;
            if(map[i][j] >= 1 && visited[i][j] == false) {
                resetVisitedMap();
                rainbowBlocks = bfs(i, j);
                if(tmpVec.size() - rainbowBlocks > 0 && tmpVec.size() >= 2) {
                    isGroup = true;
                    if(checkMaxGroup(i, j, rainbowBlocks) == true) {
                        maxBlockGroupSize = tmpVec.size();
                        maxGroupRow = i; maxGroupColumn = j;
                        maxRainbowBlocks = rainbowBlocks;
                        groupVec = tmpVec;
                        tmpVec.clear();
                    }
                }
            }
        }
    }
    if(isGroup == true) {
        return true;
    }
    else {
        return false;
    }
}

void deleteBlocksAndGetScore()
{
    for(int i = 0; i < groupVec.size(); i++) {
        int x = groupVec[i].first;
        int y = groupVec[i].second;
        map[x][y] = -2; // 블록 제거
    }
    ans += groupVec.size() * groupVec.size();
}

void setGravity()
{
    deque<int> dq;
    int preBlock = -3;
    for(int i = 1; i <= n; i++) {
        preBlock = -3;
        for(int j = n; j >= 1; j--) {
            if(map[j][i] != -1 && map[j][i] != -2) {
                if(preBlock == -2) {
                    while(!dq.empty()) {
                        if(dq.back() == -2) {
                            dq.pop_back();
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            if(map[j][i] == -1) {
                for(int k = dq.size(); k < n-j; k++) {
                    dq.push_back(-2);
                }
            }
            dq.push_back(map[j][i]);
            preBlock = map[j][i];
        }
        int blockNum = dq.size();
        for(int j = 0; j < blockNum; j++) {
            int top = dq.front();
            dq.pop_front();
            map[n-j][i] = top;
        }
        for(int j = blockNum; j < n; j++) {
            map[n-j][i] = -2; // 빈 칸
        }
    }
}

void rotateMap()
{
    int tmpMap[21][21];
    memcpy(tmpMap, map, sizeof(tmpMap));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            map[i][j] = tmpMap[j][n+1-i];
        }
    }
}

void go()
{
    bool flag = true;
    while(flag == true) {
        flag = findMaxBlockGroup();
        deleteBlocksAndGetScore();
        setGravity();
        rotateMap();
        setGravity();
    }
    cout << ans << '\n';
}

int main(void)
{
    input();
    go();
}