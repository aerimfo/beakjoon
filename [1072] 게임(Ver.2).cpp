// [1072] 게임
// 이분 탐색
#include <iostream>
#include <cmath>
#define MAX 1000000000
#define ll long long
using namespace std;

void solution(double x, double y)
{
    ll z = (floor)(100 * y / x), ans = -1;
    ll left = 1, right = MAX, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if((ll)((y + mid) / (x + mid) * 100) > z) {
            ans = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    int x, y;
    cin >> x >> y;
    solution(x, y);
    return 0;
}