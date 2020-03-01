// [1094] 막대기
// https://www.acmicpc.net/problem/1094

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int x, answer = 1;
	vector<int> stick;
	stick.push_back(64);
	cin >> x;
	while (stick[stick.size() - 1] != 1) {
		int temp = stick[stick.size() - 1] / 2;
		int sum = 0;
		stick.pop_back();
		stick.push_back(temp); stick.push_back(temp); // 가장 짧은 막대를 절반으로 자름
		for (int i = 0; i < stick.size(); i++) {
			sum += stick[i];
		}
		// 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 x보다 크거나 같다면
		if (sum - stick[stick.size() - 1] >= x) {
			// 남아있는 막대 길이의 합이 내가 얻고자 하는 길이인 경우
			if ((sum - stick[stick.size() - 1]) == x) {
				answer = stick.size() - 1;
				cout << answer;
				return 0;
			}
			stick.pop_back(); // 젤 마지막 막대기(위에서 자른 절반 중 하나) 제거
		}
	}
	cout << answer;

}