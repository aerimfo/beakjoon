// [1300] k번째 수
// https://www.acmicpc.net/problem/1300

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, k, ans = 0;
    int left, right;
    cin >> n >> k;
    left = 1, right = k;

    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++) {
            cnt += min(mid / i, n);
        }
        if(cnt < k) {
            left = mid + 1;
        }
        else if(cnt >= k) {
            right = mid - 1;
            ans = mid;
        }
        else {
            ans = mid;
            break;
        }
    }
    cout << ans << endl;
}