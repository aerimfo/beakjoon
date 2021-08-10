// [1748] 수 이어 쓰기 1
// https://www.acmicpc.net/problem/1748
// 수학, 구현
// pow -> 반환값 실수형

#include <iostream>
#include <cmath> // pow()
using namespace std;

// 자릿수 계산
int pos(int n)
{
    for(int i = 0 ; ; i++) {
        if(n / (int)pow(10, i) == 0) {
            return i;
        }
    }
}

int add(int length)
{
    int tmp = 9;
    for(int i = 1 ; i < length - 1 ; i++) {
        tmp += (i + 1) * 9 * pow(10, i);
    }
    return tmp;
}

int main(void)
{
    int n, length = 0, tmp = 0, rest = 0;
    cin >> n;
    length = pos(n);

    if(n < 10) {
        cout << n << '\n';
    }
    else {
        for(int i = 0 ; i < length - 1 ; i++) {
            tmp = tmp * 10 + 9;
        }
        rest = add(length);
        // (n - tmp) = 해당 자릿수에서 n이 나타나는 위치
        cout << length * (n - tmp) + rest << '\n';
    }

    return 0;
}