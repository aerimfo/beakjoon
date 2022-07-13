// [11404] 플로이드
// 그래프, 플로이드 워셜
#include <iostream>
#define INF 10000001
using namespace std;

int n, m, AM[101][101];

void init()
{
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) AM[i][j] = INF;
        }
    }
}

void solution()
{
    for(int k = 1; k <= n; k++) { // k : 경유지
        for(int i = 1; i <= n; i++) { // i : 출발지
            for(int j = 1; j <= n; j++) { // j : 도착지
                if(AM[i][k] + AM[k][j] < AM[i][j]) {
                    AM[i][j] = AM[i][k] + AM[k][j];
                }
            }
        }
    }
}

void printAns()
{
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(AM[i][j] == INF) cout << "0 ";
            else cout << AM[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        AM[a][b] = c < AM[a][b] ? c : AM[a][b];
    }

    solution();
    printAns();

    return 0;
}