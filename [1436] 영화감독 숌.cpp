// [1436] 영화감독 숌
// https://www.acmicpc.net/problem/1436
// 브루트포스

#include <iostream>
#include <string>
using namespace std;

int main(void) 
{
    int n, tmp = 665, cnt = 0;
    cin >> n;
    while(true) {
        tmp++;
        if(to_string(tmp).find("666") != -1) {
            cnt++;

            if(cnt == n) {
                cout << tmp << '\n';
                return 0;
            }
        }
    }
}