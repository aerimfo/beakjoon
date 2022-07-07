// [1735] 분수 합
// 수학, 정수론, 유클리드 호제법
#include <iostream>
using namespace std;

int gcd(int a, int b) //최대공약수
{
    return (a % b) != 0 ? gcd(b, a % b) : b; // 유클리드 호제법
}

int main(void)
{
    int a1, a2, b1, b2, gcdNum;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    
    gcdNum = gcd(a1*b2 + b1*a2, b1*b2);
    cout << (a1*b2 + b1*a2) / gcdNum << " " << b1*b2 / gcdNum << '\n';
}