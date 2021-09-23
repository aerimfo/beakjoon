// [14391] 종이 조각
// https://www.acmicpc.net/problem/14391
// 참고: https://vixxcode.tistory.com/23
// 브루트포스, 비트마스킹

#include <iostream>
#include <cmath>

using namespace std;
int n, m, ans, rowSum, colSum;
char paper[5][5];
bool visited[5][5];

void input()
{
    cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			cin >> paper[i][j];
		}
	}
}

void solve()
{
    for(int i = 0 ; i < pow(2, n * m) ; i++) { // 모든 경우의 수(각 칸이 0 or 1)
		int idx = 0, total = 0;
		
        // 가로 합
		for(int j = 0; j < n; j++) {
			for(int k = 0 ; k < m ; k++) {
				idx = j * m + k; // 이차원 배열을 일렬로 늘렸을 때의 인덱스
				if(i & (1 << idx)) { // 가로일 때
					rowSum = rowSum * 10 + (paper[j][k] - '0');
				}	
				else { // 세로 -> 앞에서 나온 수를 total에 더하고 sum 초기화
					total += rowSum;
					rowSum = 0;
				}
			}
			total += rowSum; 
            rowSum = 0;
		}
		
        // 세로 합
		for(int j = 0 ; j < m ; j++) {
			for(int k = 0 ; k < n ; k++) {
				idx = j + k * m; // 이차원 배열을 일렬로 늘렸을 때의 인덱스
				if((i & (1 << idx) == 0)) {
					colSum = colSum * 10 + (paper[k][j] - '0');
				}	
				else { // 가로 -> 앞에서 나온 수를 total에 더하고 sum 초기화
					total += colSum;
					colSum = 0;
				}
			}
			total += colSum; 
            colSum = 0;
		}
		ans = max(total, ans);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    input();
	solve();
	
	cout << ans << endl;
	return 0;
}