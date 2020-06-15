//[1964] 오각형, 오각형, ...
//https://www.acmicpc.net/problem/1964

#include <iostream>
using namespace std;
#define MAX 100000

int main(void)
{
	int n, time = 1;
	long rest = 0;
	long long dot[MAX];
	dot[1] = 5;
	cin >> n;
	for (int i = 2; time < n; i = i + 3)
	{
		rest += i;
		time++;
	}
	dot[n] = ((n + 1) * 5 - 5 + rest) % 45678;
	cout << dot[n];
}
