// [1244] 스위치 켜고 끄기
// https://www.acmicpc.net/problem/1244

#include <iostream>
using namespace std;

int switchCnt, state[101], students;

void output()
{
    for(int i = 1; i <= switchCnt; i++) {
        cout << state[i] << " ";
        if(i % 20 == 0) {
            cout << '\n';
        }
    }
}

void boy(int num)
{
    for(int i = num; i <= switchCnt; i += num) {
        state[i] = 1 - state[i];
    }
}

void girl(int num)
{
    state[num] = 1 - state[num];
    for(int gap = 1; num + gap <= switchCnt && num - gap >= 1; gap++) {
        if(state[num + gap] == state[num - gap]) {
            state[num + gap] = 1 - state[num + gap];
            state[num - gap] = 1 - state[num - gap];
        }
        else break;
    }
}

void input()
{
    int gender, num;
    cin >> switchCnt;
    for(int i = 1; i <= switchCnt; i++) {
        cin >> state[i];
    }
    cin >> students;
    for(int i = 0; i < students; i++) {
        cin >> gender >> num;
        if(gender == 1) boy(num);
        else girl(num);
    }

    output();
}

int main(void)
{
    input();
}