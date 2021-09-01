// [2529] 부등호
// https://www.acmicpc.net/problem/2529
// 브루트포스, 백트래킹

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
char inequal[11];
bool visited[11];
vector <string> list;

// 부등호 성립 체크
bool check(char a, char b, char oper)
{
    if(oper == '<' && (a > b)) return false;
    else if(oper == '>' && (a < b)) return false;
    return true;
}

void dfs(int cnt, string num)
{
    // (k+1)개 모두 선택
    if(cnt == k + 1) {
        list.push_back(num); // 정답 가능 리스트에 추가
        return;
    }

    for(int i = 0 ; i <= 9 ; i++) {
        if(visited[i] == false && check(num[cnt - 1], i + '0', inequal[cnt - 1])) {
            visited[i] = true;
            dfs(cnt + 1, num + to_string(i));
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> k;
    for(int i = 0 ; i < k ; i++) {
        cin >> inequal[i];
    }

    dfs(0, "");
    sort(list.begin(), list.end());
    cout << list[list.size() - 1] << '\n';
    cout << list[0] << '\n';
    return 0;
}