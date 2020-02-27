// [1541] 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
// 그리디 알고리즘

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string tmp, expr;
	int answer = 0;
	bool minus = false;
	cin >> expr; // 식 입력
	for (int i = 0; i <= expr.length(); i++) {
		// 연산자인 경우
		if ((expr[i] == '-') || (expr[i] == '+') || (expr[i] == '\0')) {
			if (minus == true)
				answer -= stoi(tmp);
			else
				answer += stoi(tmp);
			tmp = "";
		}
		if (expr[i] == '-') {
			minus = true;
			continue;
		}
		// 연산자가 아닌 경우(숫자인 경우)
		cout << "tmp = " << tmp << endl;
	}
	printf("%d\n", answer);
}