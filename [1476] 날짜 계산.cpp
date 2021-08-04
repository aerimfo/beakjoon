// [1476] 날짜 계산
// https://www.acmicpc.net/problem/1476

#include <iostream>
using namespace std;

int main(void)
{
    int E, S, M, ans = 0;
    int i = 0, j = 0, k = 0; // E, S, M
    cin >> E >> S >> M;

    while (true)
    {
        i++; j++; k++; ans++;
        if(i == E && j == S && k == M) {
            cout << ans << '\n';
            return 0;
        }
        if(i == 15) i = 0;
        if(j == 28) j = 0;
        if(k == 19) k = 0;
    }
}