/*[1158] 조세퍼스 문제*/
/*https://www.acmicpc.net/problem/1158 */
/*queue*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; i++) 
		q.push(i);
	cout << "<";
	while (q.size() > 1)
	{
		for (int i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		/*The element at the k-th front of the queue*/
		cout << q.front() << ', ';
		q.pop();
	}

	cout << q.front() << ">" << endl;
}