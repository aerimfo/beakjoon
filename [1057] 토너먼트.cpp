// [1057] 토너먼트
// https://www.acmicpc.net/problem/1057
// 브루트포스

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, jimin, hansu;

void input()
{
    cin >> n >> jimin >> hansu;
}

int tournament()
{
    int newJimin = jimin, newHansu = hansu, round = 0;

    while(newJimin != newHansu) {
        newJimin = newJimin - newJimin / 2;
        newHansu = newHansu - newHansu / 2;
        round++;
    }
    
    return round;
}

int main(void)
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    cout << tournament() << '\n';
}