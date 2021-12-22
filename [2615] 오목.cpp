// [2615] 오목
// https://www.acmicpc.net/problem/2615

#include <iostream>
#include <vector>
using namespace std;

int board[25][25];
vector<pair<int, int> > blackPosition, whitePosition;

void input()
{
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                blackPosition.push_back(make_pair(i, j));
            }
            else if(board[i][j] == 2) {
                whitePosition.push_back(make_pair(i, j));
            }
        }
    }
}

bool isWin(int x, int y, int num)
{
    if(board[x][y-1] != num && board[x][y] == num && board[x][y+1] == num && board[x][y+2] == num && board[x][y+3] == num && board[x][y+4] == num && board[x][y+5] != num) {
        return true;
    }
    else if(board[x-1][y] != num && board[x][y] == num && board[x+1][y] == num && board[x+2][y] == num && board[x+3][y] == num && board[x+4][y] == num && board[x+5][y] != num) {
        return true;
    }
    else if(board[x-1][y-1] != num && board[x][y] == num && board[x+1][y+1] == num && board[x+2][y+2] == num && board[x+3][y+3] == num && board[x+4][y+4] == num && board[x+5][y+5] != num) {
        return true;
    }
    else if(board[x+1][y-1] != num && board[x][y] == num && board[x-1][y+1] == num && board[x-2][y+2] == num && board[x-3][y+3] == num && board[x-4][y+4] == num && board[x-5][y+5] != num) {
        return true;
    }
    return false;
}

void getWinner()
{
    for(int i = 0; i < blackPosition.size(); i++) {
        int x = blackPosition[i].first;
        int y = blackPosition[i].second;


        if(isWin(x, y, 1)) {
            cout << "1" << '\n';
            cout << x+1 << " " << y+1 << '\n';
            return;
        }
    }

    for(int i = 0; i < whitePosition.size(); i++) {
        int x = whitePosition[i].first;
        int y = whitePosition[i].second;

        if(isWin(x, y, 2)) {
            cout << "2" << '\n';
            cout << x+1 << " " << y+1 << '\n';
            return;
        }
    }  

    cout << "0" << '\n';
}

int main(void)
{
    input();
    getWinner();
}