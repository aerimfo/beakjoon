// [1037] 약수
// https://www.acmicpc.net/problem/1037

#include <iostream>
#include <stack>
using namespace std;

long long factorsNum, maxFactor = 0, minFactor = 1000001;
stack <long long> factors;

void input()
{
    long long factor;
    cin >> factorsNum;
    for(int i = 0; i < factorsNum; i++) {
        cin >> factor;
        factors.push(factor);
        if(factor > maxFactor) {
            maxFactor = factor;
        }
        if(factor < minFactor) {
            minFactor = factor;
        }
    }
}

long long gcd(long long a, long long b)
{
    return (a % b) != 0 ? gcd(b, a % b) : b; // 유클리드 호제법
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

long long findN()
{
    long long n1, n2;

    while(factors.size() > 1) {
        n1 = factors.top(); factors.pop();
        n2 = factors.top(); factors.pop();
        factors.push(lcm(n1, n2));
    }

    return factors.top() == maxFactor ? maxFactor * minFactor : factors.top();
}

int main(void)
{
    input();
    cout << findN() << '\n';

    return 0;
}