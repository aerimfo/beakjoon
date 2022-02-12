// [18870] 좌표 압축
// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> info, ans;

void input()
{
    int x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        info.push_back(x);
    }
}

void solve()
{
    vector <int> temp(info);
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i < n; i++) {
        int idx = lower_bound(temp.begin(), temp.end(), info[i]) - temp.begin();
        cout << idx << ' ';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();
    
    return 0;
}