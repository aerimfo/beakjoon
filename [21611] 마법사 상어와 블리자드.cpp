// [21611] 마법사 상어와 블리자드
// https://www.acmicpc.net/problem/21611
// 참고: https://barbera.tistory.com/7
// 구현, 시뮬레이션

#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

int n, m, beadNum = 0, explodedBead[4];
int beadMap[50][50], dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
vector<pair<int, int> > magicInfo;
vector<int> beadVec;
deque<int> tmpVec;

void input()
{
    int d, s;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> beadMap[i][j];
            if(beadMap[i][j] >= 1) {
                beadNum++;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> d >> s;
        magicInfo.push_back(make_pair(d, s));
    }
}

void deleteBead(int cnt)
{
    int dir = magicInfo[cnt].first;
    int nx = (n+1)/2, ny = (n+1)/2;
    for(int i = 0; i < magicInfo[cnt].second; i++) {
        nx += dx[dir];
        ny += dy[dir];
        beadMap[nx][ny] = 0;
    }
}

int changePathDir(int dir)
{
    switch (dir)
    {
    case 1:
        return 3;
        break;
    case 2:
        return 4;
        break;
    case 3:
        return 2;
        break;
    case 4:
        return 1;
        break;
    default:
        break;
    }
}

void moveBead()
{
    int pathDir = 3, x = (n+1)/2, y = (n+1)/2;
    beadVec.clear();
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < i; k++) {
                x += dx[pathDir];
                y += dy[pathDir];
                if(beadMap[x][y] > 0) {
                    beadVec.push_back(beadMap[x][y]);
                }
            }
            pathDir = changePathDir(pathDir);
        }
    }
    for(int i = n-1; i >= 1; i--) {
        if(beadMap[1][i] > 0) {
            beadVec.push_back(beadMap[1][i]);
        }
    }
}

void explodeBead()
{
    bool flag = true;
    int continuousBead = 1, idx = 0;
    while(flag) {
        flag = false; continuousBead = 1, idx = 0; // **초기화 중요**
        for(int i = 1; i < beadVec.size(); i++) {
            if(beadVec[i] == beadVec[idx]) {
                continuousBead++;
            }
            else {
                if(continuousBead >= 4) {
                    flag = true; // 같은 번호의 구슬이 또 4개 이상 나올 수 있다는 가능성
                    explodedBead[beadVec[idx]] += continuousBead;
                    beadVec.erase(beadVec.begin() + idx, beadVec.begin() + i);
                    i -= continuousBead;
                }
                idx = i;
                continuousBead = 1;
            }
        }
        if(continuousBead >= 4) {
            flag = true;
            explodedBead[beadVec[idx]] += continuousBead;
            beadVec.erase(beadVec.begin() + idx, beadVec.end());
        }
    }
}

void changeBead()
{
    if(beadVec.size() == 0) return; // *중요*

    int standard = beadVec[0], continuousBead = 1;
    for(int i = 1; i < beadVec.size(); i++) {
        if(beadVec[i] == standard) {
            continuousBead++;
        }
        else {
            tmpVec.push_back(continuousBead);
            tmpVec.push_back(standard);
            standard = beadVec[i];
            continuousBead = 1;
        }
    }

    // 제일 마지막 원소 처리(*중요*)
    tmpVec.push_back(continuousBead);
    tmpVec.push_back(standard);

    // 구슬의 개수가 맵의 크기를 벗어난 경우 구슬 버림
    if(tmpVec.size() >= n*n) {
        while(tmpVec.size() >= n*n) {
            tmpVec.pop_back();
        }
    }
}

void updateMap()
{
    memset(beadMap, 0, sizeof(beadMap));
    int pathDir = 3, x = (n+1)/2, y = (n+1)/2;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < i; k++) {
                x += dx[pathDir];
                y += dy[pathDir];
                if(!tmpVec.empty()) {
                    beadMap[x][y] = tmpVec.front();
                    tmpVec.pop_front();
                }
                else {
                    return;
                }
            }
            pathDir = changePathDir(pathDir);
        }
    }
    for(int i = n-1; i >= 1; i--) {
        if(!tmpVec.empty()) {
            beadMap[1][i] = tmpVec.front();
            tmpVec.pop_front();
        }
        else {
            return;
        }
    }
}

void output()
{
    int ans = 0;
    for(int i = 1; i <= 3; i++) {
        ans += (i * explodedBead[i]);
    }
    cout << ans << '\n';
}

int main(void)
{
    input();
    for(int i = 0; i < m; i++) {
        deleteBead(i);
        moveBead();
        explodeBead();
        changeBead();
        updateMap();
    }
    output();
}