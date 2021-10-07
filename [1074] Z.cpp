// [1074] Z
// https://www.acmicpc.net/problem/1074
// 분할 정복

#include <iostream>
#include <cmath>
using namespace std;

int n, r, c, ans;

void input()
{
    cin >> n >> r >> c;
}

void goZ(int x, int y, int size)
{
    if (x == r && y == c) {
        cout << ans << '\n';
        exit(0);
    }

    if (r < x + size && r >= x && c < y + size && c >= y) {
        goZ(x, y, size/2);
        goZ(x, y + size/2, size/2);
        goZ(x + size/2, y, size/2);
        goZ(x + size/2, y + size/2, size/2);
    }
    else { // 내가 탐색하는 부분에 존재하지 않음 -> 이미 지나침
        ans += size * size;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    goZ(0, 0, pow(2, n));
    return 0;
}