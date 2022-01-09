// [2116] 주사위 쌓기
// https://www.acmicpc.net/problem/2116

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, sum = 0, ans = 0;
vector<int> dice[10001];

void makeSum()
{
    for(int i = 1 ; i <= n ; i++) {
        sort(dice[i].begin(), dice[i].end()); 
        //printf("%d번쨰 주사위 젤 큰 수: %d\n", i, dice[i][5]);
        sum += dice[i][5];
    }
    if(sum > ans) {
        ans = sum;
    }
}

void input()
{
    int tmp;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j < 6 ; j++) {
            cin >> tmp;
            dice[i].push_back(tmp);
        }
    }
}

void solve(int diceNum, int floor)
{
    //printf("new 바닥 수 : %d\n", floor);
    int nextFloor = 0;
    if(diceNum == n+1) {
        makeSum();
        return;
    }
    int idx = std::find(dice[diceNum].begin(), dice[diceNum].end(), floor) - dice[diceNum].begin();
    dice[diceNum][idx] = 0;
    //printf("idx: %d, dice[%d][%d] = %d\n", idx, diceNum, idx, dice[diceNum][idx]);
    if(idx == 0 || idx == 5) {
        nextFloor = dice[diceNum][5 - idx];
        dice[diceNum][5 - idx] = 0;
        solve(diceNum + 1, nextFloor);
        dice[diceNum][5 - idx] = nextFloor;
        //printf("1: dice[%d][%d] = %d\n", diceNum, 5-idx, nextFloor);
    }
    else if(idx == 1 || idx == 3) {
        nextFloor = dice[diceNum][4 - idx];
        dice[diceNum][4 - idx] = 0;
        solve(diceNum + 1, nextFloor);
        dice[diceNum][4 - idx] = nextFloor;
        //printf("2: dice[%d][%d] = %d\n", diceNum, 4-idx, nextFloor);
    }
    else {
        nextFloor = dice[diceNum][6 - idx];
        dice[diceNum][6 - idx] = 0;
        solve(diceNum + 1, nextFloor);
        dice[diceNum][6 - idx] = nextFloor;
        //printf("3: dice[%d][%d] = %d\n", diceNum, 6-idx, nextFloor);
    }
    dice[diceNum][idx] = floor;
    //printf("4: dice[%d][%d] = %d\n", diceNum, idx, dice[diceNum][idx]);
}

int main(void)
{
    input();
    for(int i = 0 ; i < 6 ; i++) {
        sum = 0;
        //printf("\n바닥 수: %d\n", dice[1][i]);
        solve(1, dice[1][i]);
    }

    cout << ans << '\n';
}