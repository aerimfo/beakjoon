// [2749] 피보나치 수3
// 수학, 분할 정복
#include <iostream>
using namespace std;

__int64_t n;
long long fibonacci[1500001];

long long solution()
{
    fibonacci[0] = 0, fibonacci[1] = 1;
    if(n < 1500000) {
        for(int i = 2; i <= n; i++) {
            fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2]) % 1000000;
        }
        return fibonacci[n];
    }
    else {
        for(int i = 2; i < 1500000; i++) {
            fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2]) % 1000000;
        }
        return fibonacci[n % 1500000];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cout << solution() << '\n';
    return 0;
}