// [14889] 스타트와 링크
// https://www.acmicpc.net/problem/14889
// 브루트포스, 백트래킹

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // abs
using namespace std;

int n, start = 0, link = 0, minGap = 1e9;
int arr[21], arr2[21], arr3[21], num[21], s[21][21];
bool visited[21], visited2[21], visited3[21];
vector <int> unSelect;

// 스타트 그룹 능력치
void getStart(int cnt)
{
    // 2개를 모두 선택했다면
    if(cnt == 3) {
        start += s[arr2[1]][arr2[2]] + s[arr2[2]][arr2[1]];
        return;
    }

    for(int i = 1 ; i <= n/2 ; i++) {
        if(visited2[i] == false && arr2[cnt - 1] < arr[i]) { // 선택한 적이 없고 직전에 선택한 수보다 크다면(조합)
            visited2[i] = true; // 선택
            arr2[cnt] = arr[i]; // 선택한 숫자 저장
            getStart(cnt + 1);
            visited2[i] = false;
        }
    }
}

// 링크 그룹 능력치
void getLink(int cnt)
{
    // 2개를 모두 선택했다면
    if(cnt == 3) {
        link += s[arr3[1]][arr3[2]] + s[arr3[2]][arr3[1]];
        return;
    }
    for(int i = 1 ; i <= n/2 ; i++) {
        if(visited3[i] == false && arr3[cnt - 1] < unSelect[i]) { // 선택한 적이 없고 직전에 선택한 수보다 크다면(조합)
            visited3[i] = true; // 선택
            arr3[cnt] = unSelect[i]; // 선택한 숫자 저장
            getLink(cnt + 1);
            visited3[i] = false;
        }
    }
}

// cnt = 현재까지 선택한 숫자의 개수
void dfs(int cnt)
{
    // n/2개를 모두 선택했다면
    if(cnt == n/2+1) {
        unSelect.clear();
        for(int i = 0 ; i <= n ; i++) {
            unSelect.push_back(i);
        }

        for(int i = 1 ; i <= n/2 ; i++) {
            std::vector<int>::iterator it = std::find(unSelect.begin(), unSelect.end(), arr[i]);
            unSelect.erase(it);
        }

        getStart(1); getLink(1); // 각 그룹 능력치 계산
        if(abs(start - link) < minGap) {
            minGap = abs(start - link);
        }
        start = 0; link = 0; // 초기화
        return;
    }

    for(int i = 1 ; i <= n ; i++) {
        if(visited[i] == false && arr[cnt - 1] < num[i]) { // 선택한 적이 없고 직전에 선택한 수보다 크다면(조합)
            visited[i] = true; // 선택
            arr[cnt] = num[i]; // 선택한 숫자 저장
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            cin >> s[i][j];
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        num[i] = i;
    }

    dfs(1);
    cout << minGap << '\n';
    return 0;
}