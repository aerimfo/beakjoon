// [14226] 이모티콘
// https://www.acmicpc.net/problem/14226
// dp, bfs

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int s;
bool visited[MAX][MAX];
 
int bfs(){
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(1, 0), 0));
    visited[1][0] = true;
 
    while(!q.empty()){
        int screen = q.front().first.first;
        int clip = q.front().first.second;
        int time = q.front().second;
        q.pop();
 
        if(screen == s) {
            return time;
        }
        // 복사
        if(screen < MAX){
            if(!visited[screen][screen]){
                visited[screen][screen] = true;
                q.push(make_pair(make_pair(screen, screen), time + 1));
            }
        }
        // 붙여넣기
        if(screen + clip < MAX){
            if(!visited[screen + clip][clip]){
                visited[screen + clip][clip] = true;
                q.push(make_pair(make_pair(screen + clip, clip), time + 1));
            }
        }
        // 제거
        if(screen > 0){
            if(!visited[screen - 1][clip]){
                visited[screen - 1][clip] = true;
                q.push(make_pair(make_pair(screen - 1, clip), time + 1));
            }
        }
    }
}
 
int main(void){
    cin >> s;
    cout << bfs() << '\n';
}
