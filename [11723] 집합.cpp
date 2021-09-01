// [11723] 집합
// https://www.acmicpc.net/problem/11723
// 구현, 비트마스킹

#include <iostream>
#include <string>
#include <cstring> // memset
using namespace std;

bool visited[21];

int main(void)
{
    // 시간 초과 방지
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, num;
    string oper;
    cin >> m;

    for(int i = 0 ; i < m ; i++) {
        cin >> oper;
        if(oper == "add") {
            cin >> num;
            visited[num] = true;
        }
        else if(oper == "remove") {
            cin >> num;
            visited[num] = false;
        }   
        else if(oper == "check") {
            cin >> num;
            if(visited[num]) cout << "1" << '\n';
            else cout << "0" << '\n';
        } 
        else if(oper == "toggle") {
            cin >> num;
            if(visited[num]) visited[num] = false;
            else visited[num] = true;
        }
        else if(oper == "all") {
            memset(visited, true, sizeof(visited));
        }
        else { // empty
            memset(visited, false, sizeof(visited));
        }
    }
    return 0;
}