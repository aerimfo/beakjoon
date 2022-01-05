// [1058] 친구
// https://www.acmicpc.net/problem/1058

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool isTwoFriend[51];
vector <int> friendship[51];
vector <int> ans;

void input()
{
    char isfriend;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> isfriend;
            if(isfriend == 'Y') {
                friendship[i].push_back(j);
            }
        }
    }
}

void dfs(int depth, int num)
{
    isTwoFriend[num] = true;
    if(depth == 2) return;

    for(int i = 0; i < friendship[num].size(); i++) {
        dfs(depth+1, friendship[num][i]);
    }
}

void findMostFamousPeople()
{
    int twoFriends = 0;

    for(int i = 0; i < n; i++) {
        twoFriends = 0;
        for(int j = 0; j < 51; j++) {
            isTwoFriend[j] = false;
        }

        dfs(0, i);

        for(int k = 0; k < n; k++) {
            if(isTwoFriend[k] == true) {
                twoFriends++;
            }
        }

        ans.push_back(twoFriends - 1); // 본인 제외
    }

    sort(ans.begin(), ans.end());
    cout << ans[n-1] << '\n';
}

int main(void)
{
    input();
    findMostFamousPeople();
}