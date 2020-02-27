// [11399] ATM
// https://www.acmicpc.net/problem/11399
// 그리디 알고리즘
// 가장 큰 숫자는 최대한 적게 더해저야 함 -> 오름차순 정렬

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n; // 사람의 수
	int time = 0, sum = 0;
	scanf("%d", &n);
	vector<int> p(n); // 각 사람이 돈을 인출하는데 걸리는 시간
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	sort(p.begin(), p.end()); // 오름차순 정렬

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			time += p[j];
		}
		sum += time;
		time = 0;
	}
	printf("%d\n", sum);
}