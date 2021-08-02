// [11054] ���� �� ������� �κ� ����
// https://www.acmicpc.net/problem/11054
// dp

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

void increase(); void decrease();
int bitonic();
int n, a[MAX] = { 0 };
int dp_inc[MAX], dp_dec[MAX];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++) { // sequence
		cin >> a[i];
	}
	increase(); decrease();
	cout << bitonic() << endl;
}

void increase()
{
	dp_inc[0] = 1;
	for (int i = 0; i < n; i++) {
		int maxl = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				maxl = max(maxl, dp_inc[j]);
		}
		dp_inc[i] = maxl + 1;
	}
}

void decrease()
{
	dp_dec[n - 1] = 1;
	for (int i = n - 1; i > 0; i--) {
		int maxl = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[i])
				maxl = max(maxl, dp_dec[j]);
		}
		dp_dec[i] = maxl + 1;
	}
}

int bitonic()
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp_inc[i] + dp_dec[i])
			max = dp_inc[i] + dp_dec[i]; //update
	}
	return max - 1;
}