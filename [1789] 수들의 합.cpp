// [1789] 수들의 합
// https://www.acmicpc.net/problem/1789
// 그리디 알고리즘

#include <iostream>
#include <cmath>
using namespace std;

long long s;

void input()
{
    cin >> s;
}

long long solve()
{
    long long ans = sqrt(2 * s);
    while(ans) {
        if(ans * (ans + 1) <= 2 * s) break;
        else ans--;  
    }
    return ans;
}

int main(void)
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();
    cout << solve() << '\n';
}