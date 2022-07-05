// [18870] 좌표 압축
// 정렬
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> x, ans;

void input()
{
    int num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        x.push_back(num);
    }
}

void solution()
{
    vector<int> tmp(x);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    for(int i = 0; i < n; i++) {
        int idx = lower_bound(tmp.begin(), tmp.end(), x[i]) - tmp.begin();
        cout << idx << ' ';
    }
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solution();
    return 0;
}