/*[2163] 초콜릿 자르기*/
/*https://www.acmicpc.net/problem/2163*/
/*초콜릿을 결국 1x1크기로 다 쪼갠다면 경우의 수는 한가지 밖에 없는데
  왜 최소 쪼개기 횟수를 구하라는건지는 모르겠음*/
#include <iostream>

using namespace std;

int main(void)
{
	int n, m,  cnt;
	cin >> n >> m;
	cnt = (n - 1) + n * (m - 1);
	cout << cnt;
}