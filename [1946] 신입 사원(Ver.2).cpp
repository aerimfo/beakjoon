// [1946] 신입 사원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> infoList;

int solution()
{
    sort(infoList.begin(), infoList.end());
    int cnt = 1, standard = infoList[0].second;

    for(int i = 1; i < infoList.size(); i++) {
        if(infoList[i].second < standard) {
            standard = infoList[i].second;
            cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, document, interview;
    cin >> t;
    while(t--) {
        infoList.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> document >> interview;
            infoList.push_back(make_pair(document, interview));
        }
        cout << solution() << '\n';
    }
    return 0;
}