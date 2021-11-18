// [1051] 숫자 정사각형
// https://www.acmicpc.net/problem/1051
// 브루트포스

#include <iostream>
#include <cmath>
using namespace std;

int n, m;
string rectangle[51];
int length;

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> rectangle[i];
    }
}

bool check(int x, int y)
{
    int vertexNum = rectangle[x][y];

    if(rectangle[x][y + length - 1] == vertexNum && rectangle[x + length - 1][y] == vertexNum && rectangle[x + length - 1][y + length - 1] == vertexNum) {
        return true;
    }

    return false;
}

int findMaxSquare()
{
    length = min(n, m);
    while(length >= 2) {
        for(int i = 0; i <= n - length; i++) {
            for(int j = 0; j <= m - length; j++) {
                if(check(i, j)) {
                    return length * length;
                }
            }
        }
        length--;
    }
    return 1;
}

int main(void)
{
    input();

    cout << findMaxSquare() << '\n';
}