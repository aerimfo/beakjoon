// [2504] 괄호의 값
// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>
using namespace std;

stack <char> s;
int valueSum = 0, tmp = 1;
bool incorrectParenthesisStr = false;
string parenthesisStr;

void input()
{
    cin >> parenthesisStr;
}

void computeCloseRoundBracket(int idx)
{
    if(s.empty()) {
        incorrectParenthesisStr = true;
        return;
    }
    if(s.top() == '(') {
        if (parenthesisStr[idx - 1] == '(') {
            valueSum += tmp;
        }
        s.pop();
        tmp /= 2;
    }
    else {
        incorrectParenthesisStr = true;
        return;
    }
}

void computeCloseSquareBracket(int idx)
{
    if(s.empty()) {
        incorrectParenthesisStr = true;
        return;
    }
    if(s.top() == '[') {
        if(parenthesisStr[idx - 1] == '[') {
            valueSum += tmp;
        }
        s.pop();
        tmp /= 3;
    }
    else {
        incorrectParenthesisStr = true;
        return;
    }
}

void printparenthesisValue()
{
    for(int i = 0; i < parenthesisStr.length(); i++) {
		if(parenthesisStr[i] == '(') {
			s.push('(');
			tmp *= 2;
		}
		else if(parenthesisStr[i] == '[') {
			s.push('[');
			tmp *= 3;
		}
		else if(parenthesisStr[i] == ')') {
            computeCloseRoundBracket(i);
		}
		else if(parenthesisStr[i] == ']') {
            computeCloseSquareBracket(i);
		}
	}
}

void printResult()
{
    if(incorrectParenthesisStr || !s.empty()) {
		cout << 0 << '\n';
	}
	else {
		cout << valueSum << '\n';
	}
}

int main(void)
{
    input();
    printparenthesisValue();
    printResult();
}