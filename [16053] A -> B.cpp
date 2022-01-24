// [16053] A -> B
// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <queue>
using namespace std;

int a, b;

void input()
{
    cin >> a >> b;
}

int bfs(int startNum, int startLevel)
{
    queue<pair<long long, int> > q;
    q.push(make_pair(startNum, startLevel));

    while(!q.empty()) {
        long long num = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(num < b) {
            q.push(make_pair(num*2, level + 1));
            q.push(make_pair(num*10 + 1, level + 1));
        }
        else if(num == b) {
            return level;
        }
    }

    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin .tie(NULL);

    input();
    cout << bfs(a, 1) << '\n';
}