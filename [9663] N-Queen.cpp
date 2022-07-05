// [9663] N-Queen
// 브루트포스, 백트래킹
#include <iostream>
using namespace std;

int n, ans = 0;
int chess[15]; // 체스가 i번째 행의 chess[i]열에 위치

bool check(int row, int column)
{
    for(int i = 0 ; i < row ; i++) {
        // 같은 열에 위치 or 대각선에 위치(|x 좌표 차이| == |y 좌표 차이|)
        if(chess[i] == column || abs(i - row) == abs(chess[i] - column)) {
            return false; // 현재 칸에 퀸 배치 불가
        }
    }
    return true; // 현재 칸에 퀸 배치 가능
}

void go(int row)
{
    if(row == n) { // 퀸 N개 다 놓음
        ans++; 
    }
    else { // 놓아야 할 퀸의 개수가 남은 경우
        for(int i = 0 ; i < n ; i++) {
            if(check(row, i)) { // 현재 열에 퀸 놓을 수 있다면
                chess[row] = i; // row행 i열에 퀸 배치
                go(row + 1); // 다음 행 탐색
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    go(0); 
    cout << ans << '\n';
}