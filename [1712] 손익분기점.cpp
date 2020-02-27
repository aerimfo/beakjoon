// [1712] 손익분기점
// https://www.acmicpc.net/problem/1712

#include <iostream>
using namespace std;

int main(void)
{
	long long a, b, c;
	int point; // break even point
	cin >> a >> b >> c;
	if (c - b > 0)
		point = a / (c - b) + 1;
	else
		point = -1;

	cout << point << endl;
}