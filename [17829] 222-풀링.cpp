// [17829] 222-풀링
// https://www.acmicpc.net/problem/17829
// 분할 정복

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, map[1025][1025];
vector<int> num;

void input()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> map[i][j];
        }
    }
}

int findSecondBig(int x, int y)
{
    num.clear();
    for(int i = x ; i < x + 2 ; i++) {
        for(int j = y ; j < y + 2 ; j++) {
            num.push_back(map[i][j]);
        }
    }

    sort(num.begin(), num.end());
    return num[2];
}

void cnn()
{
    while (n > 1) {
        for (int i = 0 ; i < n ; i += 2) {
            for (int j = 0 ; j < n ; j += 2) {
                map[i/2][j/2] = findSecondBig(i,j);
            }
        }
        n /= 2;
    }
}

int main(void)
{
    input();
    cnn();
    cout << map[0][0] << '\n';
}