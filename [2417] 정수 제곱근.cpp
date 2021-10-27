// [2417] 정수 제곱근
// https://www.acmicpc.net/problem/2417
// 수학

#include <iostream>
#include <cmath>
using namespace std;

long long n;

void input()
{
    cin >> n;
}

long long output()
{
    double ans = sqrt(n);

    if(ans - (long long)ans != 0) return (long long)ans + 1;
    else return ans;
}

int main(void)
{
    input();
    cout << output() << '\n';

    return 0;
}