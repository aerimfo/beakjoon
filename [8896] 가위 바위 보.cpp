// [8896] 가위 바위 보
// 구현
#include <iostream>
#include <cstring>
using namespace std;

string str[11];
bool isAlive[11];
int n, R, S, P, totalRound;
char lose;

void printWinner()
{
    int winnerCnt = 0, winnerRobot = 0;
    for(int i = 1; i <= n; i++) {
        if(isAlive[i] == true) {
            winnerCnt++;
            winnerRobot = i;
        }
    }
    if(winnerCnt == 1) {
        cout << winnerRobot << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

void killLoser(int round)
{
    if(R == 0) lose = 'P';
    else if(S == 0) lose = 'R';
    else lose = 'S';
    for(int j = 1; j <= n; j++) {
        if(isAlive[j] == true && str[j][round] == lose) {
            isAlive[j] = false;
        }
    }
}

void findWinner(int totalRound)
{
    for(int i = 0; i < totalRound; i++) {
        R = 0; S = 0; P = 0;
        for(int j = 1; j <= n; j++) {
            if(isAlive[j] == false) {
                continue;
            }
            if(str[j][i] == 'R') {
                R = 1;
            } 
            else if(str[j][i] == 'S') {
                S = 1;
            }
            else {
                P = 1;
            }
        }
        if(R + S + P == 2) { // 승부난 경우
            killLoser(i);
        } 
    }
    printWinner();
}

void initialization()
{
    totalRound = str[1].size();
    memset(isAlive, true, sizeof(isAlive));
}

void input()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> str[i];
        }
        initialization();
        findWinner(totalRound);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();    
}