// [16964] DFS 스페셜 저지
// https://www.acmicpc.net/problem/16964
// 그래프, dfs, 스택

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

vector<int> list[MAX], order, ans;
bool check[MAX];
int priority[MAX], n;

bool cmp(int a, int b)
{
    return priority[a] < priority[b];
}

void dfs(int x) {
	check[x] = true;
	order.push_back(x);
	
	for (int i = 0 ; i < list[x].size() ; i++) {
		if(check[list[x][i]] == false) {
            dfs(list[x][i]);
        }
	}
}

void input()
{
    int u, v, tmp;
	cin >> n;
	for (int i = 0 ; i < n - 1 ; i++) {
		cin >> u >> v;
		list[u].push_back(v); list[v].push_back(u);
	}
	
	for (int i = 0 ; i < n ; i++) {
		cin >> tmp;
		ans.push_back(tmp);
		priority[tmp] = i;
	}
}

void output()
{
    if (order == ans) {
		cout << "1" << '\n';
	}
	else {
		cout << "0" << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    input();

	for (int i = 1 ; i <= n ; i++) {
		sort(list[i].begin(), list[i].end(), cmp);
	}

	dfs(1);
    output();

	return 0;
}