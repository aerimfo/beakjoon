// [11399] ATM(Ver.2)
// https://www.acmicpc.net/problem/11399
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > withdrawTime;

void input()
{
    int time;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> time;
        withdrawTime.push_back(make_pair(time, i));
    }
}

int getMinTime()
{
    int timeSum = 0;
    sort(withdrawTime.begin(), withdrawTime.end());
    for(int i = 0 ; i < n ; i++) {
        timeSum += withdrawTime[i].first * (n - i);
    }
    return timeSum;
}

int main(void)
{
    input();
    cout << getMinTime() << '\n';
    return 0;
}