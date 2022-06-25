// [2668] 숫자 고르기
// dfs
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visited[101];
int numArr[101];
vector<int> ansVec;

void dfs(int cur, int start)
{
    if(visited[cur] == true) {
        if(cur == start) {
            ansVec.push_back(start);
        }
    }
    else {
        visited[cur] = true;
        dfs(numArr[cur], start);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> numArr[i];
    }
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, i);
    }
    cout << ansVec.size() << '\n';
    for(int i = 0; i < ansVec.size(); i++) {
        cout << ansVec[i] << '\n';
    }
}