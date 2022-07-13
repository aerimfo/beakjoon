// [11657] 타임머신
// 그래프, 벨만 포드
#include <iostream>
#include <climits>
using namespace std;

bool isNegativeCycle;
int n, m;
long long visited[501];
struct Info {
    int s; // start
    int e; // end
    int c; // cost
} info[6001];

void solution()
{
    visited[1] = 0;

    // (n-1)만큼 돌리기
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
           if(visited[info[j].s] < INT_MAX && visited[info[j].s] + info[j].c < visited[info[j].e]) {
                visited[info[j].e] = visited[info[j].s] + info[j].c;
           } 
        }
    }

    // 음수 사이클 찾기
    for(int j = 1; j <= m; j++) {
        if(visited[info[j].s] < INT_MAX && visited[info[j].s] + info[j].c < visited[info[j].e]) {
            isNegativeCycle = true;
            break;
        } 
    }
}

void printAns()
{
    if(isNegativeCycle == true) {
        cout << "-1\n";
        return;
    }
    else {
        for(int i = 2; i <= n; i++) {
            if(visited[i] == INT_MAX) cout << "-1\n";
            else cout << visited[i] << '\n';
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        visited[i] = INT_MAX;
    }
    for(int i = 1; i <= m; i++) {
        cin >> info[i].s >> info[i].e >> info[i].c;
    }

    solution();
    printAns();

    return 0;
}