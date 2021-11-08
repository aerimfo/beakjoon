// [2563] 색종이
// https://www.acmicpc.net/problem/2563

#include <iostream>
using namespace std;

int n, maxX, maxY, position[101][2], drawingPaper[101][101];

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> position[i][0] >> position[i][1];
        if(position[i][0] + 10 > maxX) maxX = position[i][0] + 10;
        if(position[i][1] + 10 > maxY) maxY = position[i][1] + 10;
    }
}

void attachPaper(int sx, int sy)
{
    for(int i = sx; i < sx + 10; i++) {
        for(int j = sy; j < sy + 10; j++) {
            switch (drawingPaper[i][j])
            {
            case 0:
                drawingPaper[i][j] = 1;
                break;
            
            case 1:
                drawingPaper[i][j] = 2;
                break;

            case 2:
                break;

            default:
                break;
            }
        }
    }
}

int getArea()
{
    int ans = 0;
    for(int i = 0; i < n; i++) {
        attachPaper(position[i][0], position[i][1]);
    }

    for(int i = 0; i <= maxX; i++) {
        for(int j = 0; j <= maxY; j++) {
            if(drawingPaper[i][j] != 0) {
                ans++;
            }
        }
    }

    return ans;
}

int main(void)
{
    input();
    cout << getArea() << '\n';
}