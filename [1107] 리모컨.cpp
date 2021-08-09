// [1107] 리모컨
// https://www.acmicpc.net/problem/1107
// 브루트포스
/* 반례:
    888
    3
    7 8 9
    정답: 116(1000번으로 간 후에 -로 888번까지 이동) -> 수학적 접근 X, 브루트 포스 O
*/

#include <iostream>
#include <string> // to_string
#include <cstdlib> // abs
#define MAX 1000001
using namespace std;

int n; // 수빈이가 이동하려는 채널
bool state[10] = {true}; // 각 버튼의 고장 여부

bool check(int num) {
	// 누르려는 번호가 0인 경우
	if (num == 0) {
		// 0번이 고장난 경우
		if (state[0] == false) return false;
		else return true;
	}
    
	while (num) {
		// 고장난 버튼인 경우
		if (state[num % 10] == false) return false;
		num /= 10;
	}

	return true;
}

int getMin(int num)
{   
	int cnt = MAX, tmp;
	for (int i = 0; i <= MAX ; i++) {
		// 누를 수 있는 번호인 경우
		if (check(i)) {
			// 누른 번호 길이
			tmp = to_string(i).length();
			// 번호를 누른 뒤 목표 번호까지 남은 거리 + or -로 추가 이동
			tmp += abs(i - num);
			// 최솟값 갱신
			cnt = min(cnt, tmp);
		}
	}
	// 100번에서 + or - 로 계속 이동하는 것과 비교
	return min(abs(num - 100), cnt);
}   

int main(void)
{
    int m, tmp;
    cin >> n >> m;

    for(int i = 0 ; i < 10 ; i++) {
        state[i] = true;
    }

    // 고장난 번호
    for(int i = 0 ; i < m ; i++) {
        cin >> tmp;
        state[tmp] = false;
    }

    cout << getMin(n) << '\n';
}