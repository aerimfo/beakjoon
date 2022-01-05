// [1106] 호텔
// https://www.acmicpc.net/problem/1106
// dp[i] = i원의 돈을 투자했을 때 최대 확보 가능 고객 수

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <pair<int, int> > info;
int c, n, dp[100001];

void input()
{
    int money, people;
    cin >> c >> n;

	for (int i = 0; i < n; i++) {
		cin >> money >> people;
		info.push_back(make_pair(money, people));
	}
}

void findMinInvestment()
{
    // 최대 십만원까지 투자 가능
    for (int i = 0; i < info.size(); i++) {
        for (int j = 1; j <= 100001; j++) {
            if(j - info[i].first >= 0) {
                dp[j] = max(dp[j], dp[j - info[i].first] + info[i].second);
            }
        }
	}

	for (int i = 1; i <= 100001; i++) {
		if(dp[i] >= c) {
			cout << i << '\n';
			break;
		}
	}
}

int main() {
    input();
    findMinInvestment();
}