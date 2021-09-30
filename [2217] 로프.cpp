// [2217] 로프
// https://www.acmicpc.net/problem/2217
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> rope;

void input()
{
    int w;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> w;
        rope.push_back(w);
    }
}

int getMaxWeight()
{
    sort(rope.begin(), rope.end());
    int max = 0, weight = 0;
    for(int i = 0 ; i < n ; i++) {
        weight = rope[i] * (n - i);
        max = weight > max ? weight : max;
    }
    return max;
}

int main(void)
{
    input();
    cout << getMaxWeight() << '\n';
}