// [21610] 마법사 상어와 비바라기
// https://www.acmicpc.net/problem/21610
// 구현, 시뮬레이션

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool preCloudsMap[51][51], postCloudsMap[51][51];
int n, m, waterMap[51][51];
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}, dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int, int> > moveInfoVec, preCloudsInfoVec, postCloudsInfoVec;

void input()
{
    int d, s;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> waterMap[i][j];
        }
    }    
    for(int i = 0; i < m; i++) {
        cin >> d >> s;
        moveInfoVec.push_back(make_pair(d, s));
    }
}

void adjustPosition(int x, int y, int idx)
{
    int dir = moveInfoVec[idx].first;
    int distance = moveInfoVec[idx].second;
    while(distance--) {
        x += dx[dir]; y += dy[dir];
        if(x > n) x = 1;
        else if(x < 1) x = n;
    
        if(y > n) y = 1;
        else if(y < 1) y  = n;
    }

    postCloudsInfoVec.push_back(make_pair(x, y));
    postCloudsMap[x][y] = true;
    waterMap[x][y]++;
}

void moveCloudsAndMakeRain(int idx)
{
    int dir = moveInfoVec[idx].first;
    int distance = moveInfoVec[idx].second;
    for(int i = 0; i < preCloudsInfoVec.size(); i++) {
        int nx = preCloudsInfoVec[i].first;
        int ny = preCloudsInfoVec[i].second;
        adjustPosition(nx, ny, idx);
    }
}

void clearClouds()
{
    preCloudsInfoVec.clear();
}

void startWaterCopyMagic()
{
    for(int i = 0; i < postCloudsInfoVec.size(); i++) {
        int cnt = 0;
        int nx = postCloudsInfoVec[i].first;
        int ny = postCloudsInfoVec[i].second;
        for(int j = 2; j <= 8; j += 2) {
            int tmpx = nx + dx[j], tmpy = ny + dy[j];
            if(tmpx < 1 || tmpx > n || tmpy < 1 || tmpy > n) {
                continue;
            }
            if(waterMap[tmpx][tmpy] >= 1) {
                cnt++;
            }
        }
        waterMap[nx][ny] += cnt;
    }
    postCloudsInfoVec.clear();
}

void makeClouds()
{
    memset(preCloudsMap, false, sizeof(preCloudsMap));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(waterMap[i][j] >= 2 && postCloudsMap[i][j] == false) {
                preCloudsMap[i][j] = true;
                preCloudsInfoVec.push_back(make_pair(i, j));
                waterMap[i][j] -= 2;
            }
        }
    }
    memset(postCloudsMap, false, sizeof(postCloudsMap));
}

void makeInitialClouds()
{
    preCloudsInfoVec.push_back(make_pair(n, 1));
    preCloudsInfoVec.push_back(make_pair(n, 2));
    preCloudsInfoVec.push_back(make_pair(n-1, 1));
    preCloudsInfoVec.push_back(make_pair(n-1, 2));
    preCloudsMap[n][1] = true;
    preCloudsMap[n][2] = true;
    preCloudsMap[n-1][1] = true;
    preCloudsMap[n-1][2] = true;
}

void go(int idx)
{
    moveCloudsAndMakeRain(idx);
    clearClouds();
    startWaterCopyMagic();
    makeClouds();
}

void output()
{
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(waterMap[i][j] > 0) {
                ans += waterMap[i][j];
            }
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    input();
    makeInitialClouds();
    for(int i = 0; i < m; i++) {
        go(i);
    }
    output();
}