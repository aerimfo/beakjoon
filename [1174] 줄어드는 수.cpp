// [1174] 줄어드는 수
// https://www.acmicpc.net/problem/1174

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector <long long> decreasingNumbers;
queue <long long> q;

void input()
{
    cin >> n;
}

long long getDecreaseNumber()
{
    long long num = 0;
    for(int i = 0; i <= 9; i++) {
        q.push(i);
        decreasingNumbers.push_back(i);
    }

    while(!q.empty()) {
        num = q.front(); q.pop();
        for(int i = 0; i < num%10; i++) {
            q.push(10 * num + i);
            decreasingNumbers.push_back(10 * num + i);
        }
    }

    return decreasingNumbers[n - 1];
}

int main(void)
{
    input();

    // 가장 큰 줄어드는 숫자 = 1023번째 수 = 9876543210
    // 10C1 + 10C2 + ... + 10C10 = 1023
    if(n > 1023) {
        cout << -1 << '\n';
    }
    else {
        cout << getDecreaseNumber() << '\n';
    }
}