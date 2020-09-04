// [1018] 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018
// 브루트 포스

#include <cstdio>
using namespace std;

char board[51][51];
char w[8][8], b[8][8];

// 시작 칸이 흰색, 검은색인 경우로 나누어 미리 8x8 크기의 체스판 설정(정답)
void chess()
{
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            if((i + j) % 2 == 0) {
                w[i][j] = 'W';
                b[i][j] = 'B';
            }
            else {
                w[i][j] = 'B';
                b[i][j] = 'W';
            }
        }
    }
}

// 해당 위치부터 8x8 크기의 체스판과 정답을 비교하여 색칠해야 하는 체스판 개수 반환
int check(char arr[8][8], int x, int y)
{
    int cnt = 0; // 색칠해야 하는 체스판 개수
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            if(arr[i][j] != board[i + x][j + y]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    int n, m, min = 1300, ans = 0;
    scanf("%d %d ", &n, &m);
    for(int i = 0 ; i < n ; i++) {
        scanf("%s", board[i]);
    }

    chess();
    for(int i = 0 ; (n - i) >= 8 ; i++) {
        for(int j = 0 ; (m - j) >= 8 ; j++) {
            // 맨 왼쪽 맨 위 칸이 하얀색인 경우
            if((ans = check(w, i, j)) < min)
                min = ans;

            // 맨 왼쪽 맨 위 칸이 검은색인 경우
            if((ans = check(b, i, j)) < min) 
                min = ans;
        }
    }
    printf("%d\n", min);
}