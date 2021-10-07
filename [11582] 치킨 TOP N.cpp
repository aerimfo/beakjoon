// [11582] 치킨 TOP N
// https://www.acmicpc.net/problem/11582
// 분할 정복

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> chickenTaste;

void input()
{
    int num;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        chickenTaste.push_back(num);
    }
    cin >> k;
}

void ctpSort()
{
    for(int i = 0 ; i < n ; i += n/k) {
        sort(chickenTaste.begin() + i, chickenTaste.begin() + i + n/k);
    }
}

void output()
{
    for(int i = 0 ; i < n ; i++) {
        cout << chickenTaste[i] << " ";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    ctpSort();
    output();

    return 0;
}