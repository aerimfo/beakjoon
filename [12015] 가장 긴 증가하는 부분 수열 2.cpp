// [12015] 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve()
{
    int n, num;
    vector <int> list;
    cin >> n; 

    for(int i = 0; i < n; i++) {
        cin >> num;
        if(list.empty() || list.back() < num) {
            list.push_back(num);
        }
        else {
            int idx = lower_bound(list.begin(), list.end(), num) - list.begin();
            list[idx] = num;
        }
    } 

    return list.size();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << solve() << '\n';

    return 0;
}