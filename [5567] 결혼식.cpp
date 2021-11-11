// [5567] 결혼식
// https://www.acmicpc.net/problem/5567

#include <iostream>
#include <vector>
using namespace std;

int inviteFriends = 0, visited[501];
vector <int> friendship[501];

void input()
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        friendship[a].push_back(b); friendship[b].push_back(a);
    }
}

void findFriendOfFriend(int studentID)
{
    for(int i = 0; i < friendship[studentID].size(); i++) {
        if(visited[friendship[studentID][i]] == false) {
            visited[friendship[studentID][i]] = true;
            inviteFriends++;
        }
    }
}

int printInviteNumber()
{
    visited[1] = true;
    for(int i = 0; i < friendship[1].size(); i++) {
        if(visited[friendship[1][i]] == false) {
            visited[friendship[1][i]] = true;
            inviteFriends++;
            findFriendOfFriend(friendship[1][i]);
        }
        else {
            findFriendOfFriend(friendship[1][i]);
        }
    }

    return inviteFriends;
}

int main(void)
{
    input();
    cout << printInviteNumber() << '\n';
}