// [3085] 사탕 게임
// https://www.acmicpc.net/problem/3085
// 브루트포스

#include <iostream>
#include <algorithm> // swap
using namespace std;

int n, ans = 0; // 보드의 크기, 정답
char board[51][51];

// 행 비교(한 줄)
void checkRow(int x)
{   
    int cnt = 1;
    char compare = board[x][0];
    for(int i = 1 ; i < n ; i++) {
        if(board[x][i] == compare) cnt++;
        else {
            cnt = 1;
            compare = board[x][i];
        } 
        if(cnt > ans) ans = cnt;
    }
}

// 열 비교(한 줄)
void checkCol(int y)
{
    int cnt = 1;
    char compare = board[0][y];
    for(int i = 1 ; i < n ; i++) {
        if(board[i][y] == compare) cnt++;
        else {
            cnt = 1;
            compare = board[i][y];
        }
        if(cnt > ans) ans = cnt;
    }
}

int main(void)
{
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> board[i][j];
        }
    }

    // 인접한 두 수가 다른 경우만 swap하면 처음부터 한 줄이 다 같은 경우는 보지 못하게 됨
    // 교환이 일어난 행, 열만 비교
    for(int i = 0 ; i < n-1 ; i++) {
        for(int j =  0 ; j < n-1 ; j++) {
            // 양 옆
            swap(board[i][j], board[i][j+1]);
            checkRow(i); checkCol(j); checkCol(j+1);
            swap(board[i][j], board[i][j+1]);

            // 위아래
            swap(board[i][j], board[i+1][j]);
            checkRow(i); checkRow(i+1); checkCol(j);
            swap(board[i][j], board[i+1][j]);
        }
    }
    // 맨 마지막 행
    for(int j = 0 ; j < n-1 ; j++) {
        swap(board[n-1][j], board[n-1][j+1]);
        checkRow(n-1); checkCol(j); checkCol(j+1);
        swap(board[n-1][j], board[n-1][j+1]);
    }

    cout << ans << '\n';
}