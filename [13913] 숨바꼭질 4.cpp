// [13913] 숨바꼭질 4
// https://www.acmicpc.net/problem/13913
// parents[다음 이동 위치] = 현재 위치
// bfs

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, seconds = 0, parents[100001]; 
bool visited[100001];
vector <int> ans;

void input()
{
	cin >> n >> k;
}

void bfs(int x, int y)
{
	visited[x] = true;
	parents[x] = x;
	queue<int> q;
	q.push(x);
	
	while(true) {
		int size = q.size(); 
		for (int i = 0; i < size; i++) {
			x = q.front();
			q.pop();
			if (x == y) {
				return;
			}
			if (0 <= x - 1 && visited[x - 1] == false) {
				q.push(x - 1);
				visited[x - 1] = true;
				parents[x - 1] = x;
			}
			if (x + 1 <= 100000 && visited[x + 1] == false) {
				q.push(x + 1);
				visited[x + 1] = true;
				parents[x + 1] = x;
			}
			if (2 * x <= 100000 && visited[2 * x] == false) {
				q.push(2 * x);
				visited[2 * x] = true;
				parents[2 * x] = x;
			}
		}
		seconds++;
	}
}

void output()
{
	cout << seconds << '\n';
	ans.push_back(k);
	int next = k;
	while(true) {
		if(next == n) {
			break;
		}
		ans.push_back(parents[next]);
		next = parents[next];
	}
	
	for(int i = ans.size() - 1 ; i >= 0 ; i--) {
		cout << ans[i] << " ";
	}
}

int main(void)
{
	cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    input();
	bfs(n, k);
	output();

	return 0;
}