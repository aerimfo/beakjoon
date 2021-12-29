// [1002] 터렛
// https://www.acmicpc.net/problem/1002

#include <iostream>
using namespace std;

int x1, y1, r1, x2, y2, r2, n;

void getRyuPosition()
{
    int d, dist1, dist2;

    d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    dist1 = (r1-r2) * (r1-r2);
    dist2 = (r1+r2) * (r1+r2);

    if(d == 0) { 
        if(dist1 == 0) { // 무한대
            cout << -1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    else if(d == dist1 || d == dist2) { // 내접 or 외접
        cout << 1 << '\n';
    }
    else if(dist1 < d && d < dist2) {
        cout << 2 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        getRyuPosition();
    }
}

int main(void)
{
    input();
}