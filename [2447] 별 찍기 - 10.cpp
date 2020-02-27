// [2447] 별 찍기 - 10
// https://www.acmicpc.net/problem/2447
// 분할 정복

#include <iostream>
using namespace std;

void draw(int x, int y, int size);

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { // 세로(column)
		for (int j = 0; j < n; j++) { // 가로(row)
			draw(i, j, n);
		}
		cout << endl;
	}
}

void draw(int x, int y, int size)
{
	// 1행 1열 -> 빈칸
	if ((x / size) % 3 == 1 && (y / size) % 3 == 1) {
		cout << " ";
	}
	else {
		if (size / 3 == 0)
			cout << "*";
		else
			draw(x, y, size / 3);
	}
}