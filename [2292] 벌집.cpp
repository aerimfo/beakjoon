//[2292] ¹úÁý
// https://www.acmicpc.net/problem/2292

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1;; i++)
	{
		if ((1 + 3 * i*(i - 1)) == n)
		{
			cout << i << endl;
			break;
		}
		else if ((1 + 3 * i*(i - 1)) < n && n <= (1 + 3 * (i + 1)*i))
		{
			cout << i + 1 << endl;
			break;
		}
	}
}