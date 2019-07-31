/*[5430] AC*/
/*https://www.acmicpc.net/problem/5430 */
/*deque = stack + queue*/
/*visual studio에서는 실행 안됨*/
#include <iostream> 
#include <deque> 
#include <string> 
#include <cstdio>

using namespace std;

int main()
{
	bool chk; 	// true이면 앞에서 false이면 뒤에서 
	bool ok; 		// 비어있을 때 D 호출하면 error
	int T, n;
	cin >> T; /*the number of test cases*/
	while (T--)
	{
		string cmd = "";
		string input_arr = ""; /*input format : [1, 2] -> string*/
		deque<int> dq;
		ok = true;
		chk = true;

		cin >> cmd; /*functions to perform*/
		cin >> n; /*the number of numbers in the array*/
		cin >> input_arr; /*the number contained in the array*/
		string num = "";	 	// dq에 넣을 수
		for (int i = 0; i < input_arr.length(); i++) 
		{  // deque로 만들기 
			if (input_arr[i] == ',' || input_arr[i] == ']') 
			{
				if (input_arr[i - 1] == '[') 		
					break; 
				dq.push_back(atoi(num.c_str()));
				num = "";
			}
			else if (input_arr[i] != '[' && input_arr[i] != ']')  
				num += input_arr[i]; 
		}
		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == 'R') /*function R*/
				chk = !chk;
			else /*function D*/
			{
				if (dq.empty())
				{
					ok = !ok;
					break;
				}
				else
				{
					if (chk)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}
		/*1. ok가 false, true
		  2. error났는지*/
		
		if (ok) 
		{
			int size = dq.size();
			cout << "[";
			for (int i = 0; i < size; i++) 
			{
				if (chk) 
				{ 
					cout << dq.front(); 
					dq.pop_front(); 
				}
				else 
				{ 
					cout << dq.back(); 
					dq.pop_back(); 
				}
				if (!dq.empty()) /*남은게 있을 경우*/
					cout << ",";
			}
			cout << "]" << endl; /*남은게 없을 경우*/
		}
		else 
			cout << "error" << endl;
	}
}