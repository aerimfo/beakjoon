// [2960] 에라토스테네스의 체
// https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k, removeCnt = 0;
vector <int> arr;

void input()
{
    cin >> n >> k;
    for(int i = 2; i <= n; i++) {
        arr.push_back(i);
    }
}

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if((n % i) == 0) {
            return false;
        }
    }
    return true;
}

int findMinPrimeNum()
{
    for(int i = 0; i < arr.size(); i++) {
        if(isPrime(arr[i])) {
            return arr[i];
        }
    }
}

void removeMultiple(int minPrimeNum)
{
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] % minPrimeNum == 0) {
            removeCnt++;
            if(removeCnt == k) {
                cout << arr[i];
                exit(0);
            }
            arr.erase(arr.begin() + i);
        }
    }
}

void eratos()
{
    while(!arr.empty()) {
        int minPrimeNum = findMinPrimeNum();
        removeMultiple(minPrimeNum);
    }
}

int main(void)
{
    input();
    eratos();
}