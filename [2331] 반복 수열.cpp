/*[2331] 반복 수열*/
/*https://www.acmicpc.net/problem/2331*/

#include <iostream>
#include <math.h>
using namespace std;
int sequential_s(int, int, int);
int d[1000000];

int main(void)
{
	int a, p;
	cin >> a >> p;
	cout << sequential_s(a, p, 1);
}

int sequential_s(int a, int p, int n)
{
	int result = 0;
	if (d[a] != 0)
		return d[a] - 1;
	d[a] = n;
	while (a > 0)
	{
		result += pow(a % 10, p);
		a /= 10;
	}
	return sequential_s(result, p, n + 1);
}