#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if ((n + 7) % 8 == 0)
		cout << 1;
	else if ((n + 6) % 8 == 0 || (n % 8 == 0))
		cout << 2;
	else if ((n + 1) % 4 == 0)
		cout << 3;
	else if ((n + 4) % 8 == 0 || (n + 2) % 8 == 0)
		cout << 4;
	else if ((n + 3) % 8 == 0)
		cout << 5;
	return 0;
}