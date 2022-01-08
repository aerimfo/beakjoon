// [1166] 선물
// https://www.acmicpc.net/problem/1166

#include <iostream>
#include <cmath>
using namespace std;

long double n, l, w, h;

void input()
{
    cin >> n >> l >> w >> h;
}

void findMaxA()
{
    long double start = 0, mid = 0;
    long double end = min(l, min(w, h));

    // 반복문을 충분히 돌려 오차 줄임
    for(int i = 0; i < 10000; i++) {
        mid = (start + end) / 2;
        // 1e27은 long long으로 표현 불가능 -> 다 따로 분리해서 계산 -> (l*w*h / mid*mid*mid)(x)
        if((long long)(l/mid) * (long long)(w/mid) * (long long)(h/mid) >= n) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    cout.precision(20);
    cout << mid << '\n';
}

int main(void)
{
    input();
    findMaxA();
}