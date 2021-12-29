// [1024] 수열의 합
// https://www.acmicpc.net/problem/1024

#include <iostream>
using namespace std;

long long n, l;

void input()
{
    cin >> n >> l;
}

void findShortestArray()
{
    int start = 0, length = 0;

    for(int i = l; i <= 100; i++) {
        int tmp = i * (i-1) / 2;
        if((n - tmp) % i == 0 && n >= tmp) {
            start = (n - tmp) / i;
            length = i;
        
            for(int i = start; i < start+length; i++) {
                cout << i << " ";
            }
            exit(0);
        }
    }  

    cout << -1 << '\n';
    return;
}

int main(void)
{
    input();
    findShortestArray();
}