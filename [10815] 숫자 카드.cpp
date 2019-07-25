#include <algorithm> /*binary_search(), sort()*/
#include <iostream>
#include <vector>
#include <stdio.h>
#define MAX 500001

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
		printf("%d ", binary_search(sang.begin(), sang.end(), num));
		/*bool형 데이터를 %d로 출력하면true = 1, false = 0 출력*/
	}
	return 0;
}