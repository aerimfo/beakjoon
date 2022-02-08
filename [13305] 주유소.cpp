// [13305] 주유소
// https://www.acmicpc.net/problem/13305
// 그리디

#include <iostream>
using namespace std;

int n, length[100001], cost[100001];

void input()
{
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> length[i];
    }    
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
}

long long getMinCost()
{
    int minCost = cost[0];
    long long ans = 0;
    ans += (long long)length[0] * (long long)cost[0];

    for(int i = 1; i < n-1; i++) {
        if(cost[i] > minCost) {
            ans += (long long)length[i] * (long long)minCost;
        }
        else {
            ans += (long long)length[i] * (long long)cost[i];
            minCost = cost[i];
        }
    }

    return ans;
}

int main(void)
{
    input();
    cout << getMinCost() << '\n';

    return 0;
}