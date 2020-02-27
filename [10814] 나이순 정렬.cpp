//[10814] 나이순 정렬
//https://www.acmicpc.net/problem/10814

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, age;
	char name[101];
	vector<string> v[201];
	cin >> n;
	for (int i = 0; i < n; i++) //나이에 해당하는 index에 이름 저장
	{
		cin >> age;
		cin >> name;
		v[age].push_back(name);
	}
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < v[i].size(); j++) {
			cout << i << " ";
			cout << v[i][j] << '\n'; //endl을 사용하는 경우 시간 초과
		}
	}
	return 0;
}