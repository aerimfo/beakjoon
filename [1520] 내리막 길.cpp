// [1520] 내리막 길
// https://www.acmicpc.net/problem/1520
// dp

#include <cstdio>
using namespace std;
 
int m, n;
int height[501][501];
int dp[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
 
int dfs(int x, int y)
{   
    // 목적지에 도착하면 최초 경우의 수 1 반환
    if(x == m && y == n) return 1;
 
    // 방문한 적 없다면
    if(dp[x][y] == -1) {
        dp[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 인덱스가 범위 안에 있는지 체크
            if(nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                if(height[x][y] > height[nx][ny]) {
                    // 도착지점에서부터 출발지점까지 역순으로 경우의 수를 추가하면서 채워나간다.
                    dp[x][y] += dfs(nx, ny);
                }
            }
        }
    }

    return dp[x][y];
}
 
int main(void)
{
    scanf("%d %d", &m, &n);
    for(int i = 1 ; i <= m ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            scanf("%d", &height[i][j]);
            dp[i][j] = -1; // 방문하지 않음
        }
    }
    printf("%d\n", dfs(1, 1));
    return 0;
}
