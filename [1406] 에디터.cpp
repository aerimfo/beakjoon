/*[1406] ¿¡µðÅÍ*/
/*https://www.acmicpc.net/problem/1406*/
/*Divide left and right stack by cursor*/

#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	stack<char> left, right;
	string s;
	cin >> s; /*input string*/
	int len = s.length();
	for (int i = 0; i < len; i++) 
		left.push(s[i]); /*Put it all on the left stack*/
	int N;
	cin >> N; /*the number of commands to input*/
	
	while (N--)
	{
		char command;
		cin >> command;
		if (command == 'L' && !left.empty())
		{
			/*Take out the top of the left stack and place it on the right stack*/
			right.push(left.top());
			left.pop();
		}
		else if (command == 'D' && !right.empty())
		{
			/*Take out the top of the right stack and place it on the left stack*/
			left.push(right.top());
			right.pop();
		}
		else if (command == 'B' && !left.empty())
			left.pop(); /*delete*/
		else if (command == 'P')
		{
			char $;
			cin >> $;
			left.push($);
		}
	}
	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while (!right.empty())
	{
		printf("%c", right.top());
		right.pop();
	}
}