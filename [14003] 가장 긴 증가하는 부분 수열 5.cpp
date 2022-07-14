// [14003] 가장 긴 증가하는 부분 수열 5
// 이분 탐색, dp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, dp[1000001], p[1000001] = {-1, }; // p[i] = i번째 수 앞에 있어야 하는 수의 index 번호
struct Info {
    int value;
    int idx;
    inline bool operator<(const Info &ref) const {
        return this -> value < ref.value;
    }
};
vector<int> ansLIS;
vector<Info> a, tmpLIS;

void solution()
{
    tmpLIS.push_back({a[0].value, a[0].idx});

    for(int i = 0; i < n; i++) {
        int idx = lower_bound(tmpLIS.begin(), tmpLIS.end(), a[i]) - tmpLIS.begin();
        if(idx < tmpLIS.size()) {
            tmpLIS[idx].value = a[i].value;
            tmpLIS[idx].idx = a[i].idx;
            if(idx == 0) {
                dp[i] = 1;
                p[i] = -1;
            }
            else {
                dp[i] = dp[tmpLIS[idx - 1].idx] + 1;
                p[i] = tmpLIS[idx - 1].idx;
            }
        }
        else {
            tmpLIS.push_back({a[i].value, i});
            dp[i] = dp[tmpLIS[idx - 1].idx] + 1;
            p[i] = tmpLIS[idx - 1].idx;
        }
    }

    int maxLength = 0, maxIdx = 0;
    for(int i = n-1; i >= 0; i--) {
        if(dp[i] > maxLength) {
            maxIdx = i;
            maxLength = dp[i];
        }
    }

    int i = maxIdx;
    while(p[i] != -1) {
        ansLIS.push_back(a[i].value);
        i = p[i];
    }
    ansLIS.push_back(a[i].value);
}

void printAns()
{
    cout << ansLIS.size() << '\n';
    for(int i = ansLIS.size() - 1; i >= 0; i--) {
        cout << ansLIS[i] << " ";
    }
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        a.push_back({num, i});
        p[i] = -1;
    }

    solution();
    printAns();

    return 0;
}