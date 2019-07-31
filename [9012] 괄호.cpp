/*[9012] 괄호*/
/*https://www.acmicpc.net/problem/9012*/
/*VPS = Valid Parenthesis String = 올바른 괄호 문자열*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string VPS(string str);

int main() 
{
	int T; /*the number of test datas*/
	cin >> T;
	while (T--) 
	{
		string str;
		cin >> str; /*input parenthesis string*/
		cout << VPS(str) << endl; /*output result : YES / NO*/
	}
}

string VPS(string str)
{
	stack<char>s; /*stack 생성*/
	int len = str.length(); 
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
			s.push('('); /*1. '('이 들어가면*/
		else
		{
			if (s.empty()) /*3. 그렇지 못하다면 쌍이 안맞는다는 소리*/
				return "NO";
			else
				s.pop(); /*2. ')'이 무조건 나와야하는데*/
		}
	}
	/*If it is not returned in the above for statement and the stack is empty, 
	  it means vps*/
	if (s.empty())
		return "YES";
	else
		return "NO";
}