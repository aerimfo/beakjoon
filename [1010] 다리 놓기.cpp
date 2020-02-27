//[1010] 다리 놓기
// https://www.acmicpc.net/problem/1010

#include <iostream>
using namespace std;
int bridge(int n, int m);
long num[30][30]; // 다리를 지을 수 있는 경우의 수
int n, m; // 0 < N <= M < 30

int main(void)
{
	int t; // number of test case
	cin >> t;
	while (t > 0)
	{
		cin >> n >> m;
		cout << bridge(n, m) << endl;
		t--;
	}
}

int bridge(int n, int m)
{
	long temp1 = 0, temp2 = 0;
	for (int i = 1; i < 30; i++)
		num[1][i] = i;

	for (int i = 2; i < 30; i++) {
		temp1 = 0;
		for (int j = 0; j <= i - 2; j++) {
			temp1 += (j + 1);
		}
		num[2][i] = temp1;
	}
	for (int i = 3; i < 30; i++) { // n
		for (int j = 3; j < 30; j++) { // m
			temp2 = 0;
			for (int k = i - 1; k <= j - 1; k++) { // k < (i-1)+j-1 = j-1
				temp2 += num[i - 1][k];
			}
			num[i][j] = temp2;
		}
	}
	return num[n][m];
}