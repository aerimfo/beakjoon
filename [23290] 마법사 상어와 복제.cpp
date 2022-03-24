// [23290] 마법사 상어와 복제
// https://www.acmicpc.net/problem/23290

#include <iostream>
#include <vector>
using namespace std;

struct fishInfo
{
    int x;
    int y;
    int dir;
};
int s, sx, sy, maxDeletedFish = -1;
int tmpPath[3], maxPath[3], fishSmellMap[5][5];
int sharkDirX[5] = {0, -1, 0, 1, 0}, sharkDirY[5] = {0, 0, -1, 0, 1};
int fishDirX[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}, fishDirY[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
vector <fishInfo> fishMap[5][5], cloneFishMap[5][5];

void input()
{
    int m, fx, fy, d;
    cin >> m >> s;
    for(int i = 0; i < m; i++) {
        cin >> fx >> fy >> d;
        fishInfo f = {fx, fy, d};
        fishMap[fx][fy].push_back(f);
    }    
    cin >> sx >> sy;
}

void moveFish()
{
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = 0; k < fishMap[i][j].size(); k++) {
                bool isMovable = false;
                int x = fishMap[i][j][k].x;
                int y = fishMap[i][j][k].y;
                int dir = fishMap[i][j][k].dir;
                for(int l = 0; l < 8; l++) {
                    int nx = x + fishDirX[dir];
                    int ny = y + fishDirY[dir];
                    if(1 <= nx && nx <= 4 && 1 <= ny && ny <= 4) {
                        if(nx != sx || ny != sy) {
                            if(fishSmellMap[nx][ny] == 0) {
                                isMovable = true;
                                fishInfo f = {nx, ny, dir};
                                cloneFishMap[nx][ny].push_back(f);
                                break;
                            }
                        }
                    }
                    dir--;
                    if(dir < 1) dir = 8;
                }
                if(isMovable == false) {
                    fishInfo f = {x, y, dir};
                    cloneFishMap[x][y].push_back(f);
                }
            }
        }
    }
}

void checkMaxCase()
{
    bool visited[5][5] = {false,};
    int deletedFish = 0, tx = sx, ty = sy;
    for(int i = 0; i < 3; i++) {
        int dir = tmpPath[i];
        tx += sharkDirX[dir];
        ty += sharkDirY[dir];
        if(tx < 1 || tx > 4 || ty < 1 || ty > 4) {
            return;
        }
        if(visited[tx][ty] == false) {
            deletedFish += cloneFishMap[tx][ty].size();
            visited[tx][ty] = true;
        }
    }
    if(deletedFish > maxDeletedFish) {
        maxDeletedFish = deletedFish;
        deletedFish = 0;
        for(int i = 0; i < 3; i++) {
            maxPath[i] = tmpPath[i];
        }
    }
}

void repeatedPermutation(int depth)
{   
    if(depth == 3) {
        checkMaxCase();
        return;
    }

    for(int i = 1; i <= 4; i++) {
        tmpPath[depth] = i;
        repeatedPermutation(depth + 1);
    }
}

void moveShark(int level)
{
    maxDeletedFish = -1;
    repeatedPermutation(0);
    for(int i = 0; i < 3; i++) {
        int dir = maxPath[i];
        sx += sharkDirX[dir]; sy += sharkDirY[dir];
        if(cloneFishMap[sx][sy].size() > 0) { // 해당 칸에 물고기가 있다면
            fishSmellMap[sx][sy] = level; // 물고기 냄새 남김
            cloneFishMap[sx][sy].clear();
        }
    }
}

void deleteTwoTimesAgoSmell(int level)
{
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            if(fishSmellMap[i][j] == (level-2) && level > 2) {
                fishSmellMap[i][j] = 0;
            }
        }  
    }
}

void copyMap()
{
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = 0; k < cloneFishMap[i][j].size(); k++) {
                fishMap[i][j].push_back(cloneFishMap[i][j][k]);
            }
            cloneFishMap[i][j].clear();
        }
    }
}

void startMagic(int level)
{
    moveFish();
    moveShark(level);
    deleteTwoTimesAgoSmell(level);
    copyMap();
}

void getLeftFish()
{
    int ans = 0;
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            ans += fishMap[i][j].size();
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    input();
    for(int i = 1; i <= s; i++) {
        startMagic(i);
    }
    getLeftFish();

    return 0;
}