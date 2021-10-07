// [18222] 투에-모스 문자열
// https://www.acmicpc.net/problem/18222
// 분할 정복

#include <iostream>
using namespace std;

long long k;

long long thueMorse(long long n)
{
    if(n == 0) return 0;
    if(n % 2 == 0) { // T2n = Tn
        return thueMorse(n / 2);
    }
    else { // T(2n+1) = 1 - Tn
        return 1 - thueMorse(n / 2);
    }
}

int main(void)
{
    cin >> k;
    cout << thueMorse(k - 1) << '\n';

    return 0;
}