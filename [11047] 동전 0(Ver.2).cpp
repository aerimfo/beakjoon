// [11047] 동전 0(Ver.2)
// https://www.acmicpc.net/problem/11047
// 그리디 알고리즘

#include <iostream>
#define MAX 1000001
using namespace std;

int n, k, a[MAX];

void input()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
}

int makeK()
{
    int cnt = 0;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(k > 0 && k / a[i] >= 1) {
            cnt += k / a[i];
            k -= (k / a[i]) * a[i];
        }   
    }
    return cnt;
}

int main(void)
{
    input();
    cout << makeK() << '\n';
}