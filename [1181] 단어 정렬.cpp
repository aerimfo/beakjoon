//[1181] 단어 정렬
// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector< pair<int, string> > word(n); // 단어의 길이, 단어

	for (int i = 0; i < n; i++)
	{
		cin >> word[i].second;
		word[i].first = word[i].second.length();
	}

	sort(word.begin(), word.end()); // 길이가 짧은 순으로 정렬

	for (int i = 0; i < n - 1; i++)
	{
		// 중복 제거
		if (word[i].second == word[i + 1].second)
			;
		else
			cout << word[i].second << endl;
	}
	cout << word[n - 1].second << endl;
}