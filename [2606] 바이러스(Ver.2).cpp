// [2606] 바이러스
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int computers, connectedComputers, visited[101];
stack <int> computerStack;
vector <int> computerVec[101];

void input()
{
    int u, v;
    cin >> computers >> connectedComputers;

    for(int i = 0; i < connectedComputers; i++) {
        cin >> u >> v;
        computerVec[u].push_back(v); computerVec[v].push_back(u);
    }
}

int getVirusComputers()
{
    int ans = 0;

    computerStack.push(1);
    visited[1] = true;
    while(!computerStack.empty()) {
        int start = computerStack.top();

        for(int i = 0; i < computerVec[start].size(); i++) {
            if(visited[computerVec[start][i]] == false) {
                ans++;
                computerStack.push(computerVec[start][i]);
                visited[computerVec[start][i]] = true;
            }
        }
    }

    return ans;
}

int main(void)
{
    input();
    cout << getVirusComputers() << '\n';
}