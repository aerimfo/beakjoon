// [2668] 숫자고르기
// https://www.acmicpc.net/problem/2668
// dfs
// cycle 개수 찾기!

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int, int);
int visited[102] = { 0 };
int a[102];
vector<int> answer;

int main(void)
{
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, i);
		// ***initialization***
		for (int j = 1; j <= n; j++) 
			visited[j] = 0;
	}
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
}

void dfs(int start, int current)
{
	if (visited[current]) { 
		if (current == start) { // cycle인 경우
			answer.push_back(start);
		}
	}
	else {
		visited[current]++;
		dfs(start, a[current]);
	}
}