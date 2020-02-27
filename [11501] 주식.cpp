/*[11501] аж╫д*/
/*https://www.acmicpc.net/problem/11501*/

#include <iostream>
#define MAX 1000001
using namespace std;

int main(void)
{
	int stock[MAX];
	int t, n;
	long long sum;
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> stock[i];

		int max = stock[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if (stock[i] < max)
				sum += max - stock[i];
			else
				max = stock[i];
		}
		cout << sum << endl;
	}
}