// [2748] 피보나치 수2
// dp
#include <iostream>
using namespace std;

int n;
long long fibonacci[91];

void solution()
{
    fibonacci[0] = 0, fibonacci[1] = 1;
    for(int i = 2; i <= n; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    cout << fibonacci[n] << '\n';
}

int main(void)
{
    cin >> n;
    solution();
    return 0;
}