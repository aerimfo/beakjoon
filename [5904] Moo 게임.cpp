// [5904] Moo 게임
// https://www.acmicpc.net/problem/5904
// 분할 정복

#include <iostream>
using namespace std;

int n;

void moo()
{
    int length = 3, midLength = 3; // midLength: o가 k+2개인 부분 길이

    while(n > length) {
        length = length * 2 + (++midLength); 
        /* (midLength + 1)로 하는 경우 시간 초과
            why? (midLength + 1)은 메모리에 접근, ++midLength은 메모리에 접근하지 않음 */
    }

    while(true) {
        int preLength = (length - midLength) / 2;

        if(n <= preLength) { // s(k-1)
            midLength--; // o 1개 제거
            length = preLength;
        }
        else if(n > preLength + midLength) { // s(k-1)
            n -= preLength + midLength;
            midLength--; // o 1개 제거
            length = preLength;
        }
        else { // m o o ...
            n -= preLength;
            break;
        }
    }
}

void output()
{
    if(n == 1) cout << "m";
    else cout << "o";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    moo();
    output();

    return 0;
}