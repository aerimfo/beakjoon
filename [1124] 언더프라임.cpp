// [1124] 언더프라임
// https://www.acmicpc.net/problem/1124

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a, b;
vector <int> primeNumbers;

void input()
{
    cin >> a >> b;
}

bool isPrime(int num)
{
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void makePrimeNumArr()
{
    for(int i = 2; i <= b; i++) {
        if(isPrime(i)) {
            primeNumbers.push_back(i);
        }
    }
}

bool isUnderPrime(int num)
{
    int aliquot = 0;
    int idx = 0;
    while(primeNumbers[idx] <= num) {
        if(num % primeNumbers[idx] == 0) {
            aliquot++;
            num = num / primeNumbers[idx];
        }
        else {
            idx++;
        }
    }

    if(isPrime(aliquot)) {
        return true;
    }
    else {
        return false;
    }
}

void getUnderPrimeNum()
{
    int ans = 0;
    makePrimeNumArr();
    
    for(int i = a; i <= b; i++) {
        if(isUnderPrime(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    input();
    getUnderPrimeNum();
}