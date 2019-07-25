#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int>sang;
	int n, m; /*상근이가 가지고 있는 숫자 카드의 개수*/
	cin >> n;
	for (int i = 0; i < n; i++) /*상근이가 가지고 있는 카드*/
	{
		int num;
		scanf("%d", &num);
		sang.push_back(num);
	}
	sort(sang.begin(), sang.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		/*upper_bound(배열의 시작, 배열의 끝, 찾고 싶은 수)*/
		cout << upper_bound(sang.begin(), sang.end(), num) - lower_bound(sang.begin(), sang.end(), num) << " ";
	}
}