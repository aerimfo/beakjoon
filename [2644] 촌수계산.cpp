// [2644] 촌수계산
// https://www.acmicpc.net/problem/2644

#include <iostream>
#include <vector>
using namespace std;

vector<int> rel[101]; // 관계
bool visited[101] = {false};
int to, kinship = 0;

void find(int from)
{
    if(from == to) { // 목적지 도착
        cout << kinship << '\n';
        exit(0);
    }

    visited[from] = true;

    for(int i = 0 ; i < rel[from].size() ; i++) {
        int next = rel[from][i];
        
        if(visited[next] == false) { // 방문한 적이 없는 경우
            kinship++;
            find(next); // 탐색
        }
    }
    kinship--; // 핵심... 목적지를 못찾아서 되돌아가는 것이기 때문에 kinship을 1 감소시켜야 함
    return;
}

int main(void)
{
    int n, from, m, parent, child; // 전체 사람의 수, 촌수 계산할 사람들, 부모-자식 관계 수, 부모, 자식
    cin >> n >> from >> to >> m;
    
    for(int i = 0 ; i < m ; i++) {
        cin >> parent >> child;
        rel[parent].push_back(child); rel[child].push_back(parent);
    }

    find(from);
    cout << -1 << '\n';
    return 0;
}