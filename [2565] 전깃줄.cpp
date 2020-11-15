// [2565] 전깃줄
// https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, l, r, it;
    vector <pair<int, int> > num;
    vector <int> ans;
    cin >> n;
    ans.push_back(0);
    for(int i = 0 ; i < n ; i++) {
        cin >> l >> r;
        num.push_back(make_pair(l, r));
    }
    sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); i++) {
		if (ans.back() < num[i].second) {
			ans.push_back(num[i].second);
		}
		else {
			it = lower_bound(ans.begin(), ans.end(), num[i].second) - ans.begin();
			ans[it] = num[i].second;
		}
	}

	cout << num.size() - (ans.size() - 1) << '\n';
}