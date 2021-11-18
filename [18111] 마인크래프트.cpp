// [18111] 마인크래프트
// https://www.acmicpc.net/problem/18111
// 브루트포스

#include <iostream>
#include <limits>
using namespace std;

int n, m, b, minHeight = 256, maxHeight = 0, groundHeight[501][501];

void input()
{
    cin >> n >> m >> b; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> groundHeight[i][j];
            if(groundHeight[i][j] > maxHeight) maxHeight = groundHeight[i][j];
            if(groundHeight[i][j] < minHeight) minHeight = groundHeight[i][j];
        }
    }
}

int getTimeAndHeight(int height)
{
    int time = 0, inventory = b;
    // height보다 높은 것
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(groundHeight[i][j] > height) {
                time += (groundHeight[i][j] - height) * 2;
                inventory += (groundHeight[i][j] - height);
            }
        }
    }

    // height보다 낮은 것
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(groundHeight[i][j] < height) {
                time += (height - groundHeight[i][j]);
                inventory -= (height - groundHeight[i][j]);
                if(inventory < 0) return -1;
            }
        }
    }

    return time;
}

void makeGroundEven()
{
    int ansTime = std::numeric_limits<int>::max(), ansHeight = 0, time = 0;
    
    for(int i = minHeight; i <= maxHeight; i++) {
        time = getTimeAndHeight(i);
        if(time != -1 && time <= ansTime) {
            ansTime = time;
            ansHeight = i;
        }
    }

    cout << ansTime << " " << ansHeight << '\n';
}

int main(void)
{
    input();
    makeGroundEven();
}