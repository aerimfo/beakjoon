// [1629] 곱셈
// https://www.acmicpc.net/problem/1629

#include <iostream>
using namespace std;

long long ans;
int c;

long long pow(int m, int n) {
    if(n == 0) {
        return 1;
    }
    ans = pow(m, n/2);
    // m이 짝수인 경우
    if(n % 2 == 0) {
        return ans*ans % c;
    }
    // m이 홀수인 경우
    else {
        return (ans*ans % c)*m % c;
    }
}

int main(void)
{
    int a, b;
    cin >> a >> b >> c;

    cout << pow(a, b) << endl;
    return 0;
}