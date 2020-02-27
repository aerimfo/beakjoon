// [1475] 방 번호
// https://www.acmicpc.net/problem/1475

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void)
{
	string n; // 다솜이의 방 번호
	int exist[10] = { 0 }; // 방번호 중 각 숫자의 개수
	int set = 0; // 필요한 세트의 개수
	cin >> n;
	
	for (int i = 0; i < n.size(); i++) {
		exist[n[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 6) // 숫자가 6인 경우
			continue; 
		if (i == 9) { // 숫자가 9인 경우
			for (int j = 0;; j += 2) {
				if (exist[6] + exist[9] <= j) {
					if (set >= j / 2) 
						;

					// 필요한 세트가 현재 세트의 개수를 초과할 경우
					else 
						set += j / 2 - set; // **차이만큼을 더해줘야한다**
					break;
				}
			}
			break;
		}
		// 숫자가 한번도 나오지 않은 경우
		if (exist[i] == 0)
			;
		// 숫자가 한 번 이상 나온 경우
		else {
			if (exist[i] > set)
				set += exist[i] - set;
			else
				;
		}
	}
	cout << set << endl;
}