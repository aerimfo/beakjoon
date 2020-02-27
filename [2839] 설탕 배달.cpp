// [2839] 설탕 배달
// https://www.acmicpc.net/problem/2839

#include <iostream>

using namespace std;

int main(void)
{
	int n, three = 0, five = 0; // 상근이가 배달해야하는 무게, 3kg 봉지 개수, 5kg 봉지 개수
	cin >> n;
							
	if (n % 5 == 0) {
		five = n / 5;
		cout << three + five;
		return 0;
	}
	for (int i = 0; (n - i * 3) > 0; i++) {
		if ((n - i * 3) % 5 == 3) {
			five = (n - i * 3) / 5;
			three = i + 1;
			cout << three + five;
			return 0;
		}
	}
	cout << "-1" << endl;
}