// [9466] 텀 프로젝트
// https://www.acmicpc.net/problem/9466
// bfs, dfs

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100001
using namespace std;

queue<int> q;
int check[MAX];
int cycle[MAX], a[MAX];
int cnt = 0; // 프로젝트 팀에 속하는 학생들의 수
void dfs(int s);

int main(void)
{
	int t, n, student;
	int answer[MAX];
	cin >> t;
	
	for (int i = 0; i < t;i++) {
		cin >> n;
		
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		
		for (int k = 1; k <= n; k++) {
			if (check[k] == false) {
				dfs(k);
			}
		}
		
		answer[i] = n - cnt;
	
		// initialization
		cnt = 0;
		memset(check, false, sizeof(check));
		memset(cycle, false, sizeof(cycle));
	}

	for (int i = 0; i < t; i++)
		cout << answer[i] << endl;
}

void dfs(int s)
{
	check[s] = true;
	int next = a[s];
	if (!check[next])
		dfs(next);
	else if (!cycle[next]) {
		for (int i = next; i != s; i = a[i]) {
			cnt++;
		}
		cnt++;
	}
	cycle[s] = true;
}
