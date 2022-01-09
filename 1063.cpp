// [1063] 킹
// https://www.acmicpc.net/problem/1063

#include <iostream>
using namespace std;

string kingPosition, stonePosition, moveDir[51];
int n, kingR, kingC, stoneR, stoneC;

void input()
{
    cin >> kingPosition >> stonePosition >> n;
    for(int i = 0; i < n; i++) {
        cin >> moveDir[i];
    }
}

void initialization()
{
    kingR = kingPosition[1] - '0';
    kingC = kingPosition[0] - 'A';
    stoneR = stonePosition[1] - '0';
    stoneC = stonePosition[0] - 'A';
}

void output()
{
    cout << (char)(kingC + 'A');
    cout << kingR << '\n';
    cout << (char)(stoneC + 'A');
    cout << stoneR << '\n';
}

void move()
{
    for(int i = 0; i < n; i++) {
        if(moveDir[i] == "R") {
            if(kingC + 1 < 8) {
                if(kingC + 1 == stoneC) {
                    if(stoneC + 1 < 8) {
                        kingC++; stoneC++; continue;
                    }
                    else continue;
                }
                kingC++;
            }
        }
        else if(moveDir[i] == "L") {
            if(kingC - 1 >= 0) {
                if(kingC - 1 == stoneC) { 
                    if(stoneC - 1 >= 0) {
                        kingC--; stoneC--; continue;
                    }
                    else continue;
                }
                kingC--;
            }
        }
        else if(moveDir[i] == "B") {
            if(kingR - 1 >= 1) {
                if(kingR - 1 == stoneR) {
                    if(stoneR - 1 >= 1) {
                        kingR--; stoneR--; continue;
                    }
                    else continue;
                }
                kingR--;
            }
        }
        else if(moveDir[i] == "T") {
            if(kingR + 1 < 9) {
                if(kingR + 1 == stoneR) {
                    if(stoneR + 1 < 9) {
                        kingR++; stoneR++; continue;
                    }
                    else continue;
                }
                kingR++;
            }
        }
        else if(moveDir[i] == "RT") {
            if(kingC + 1 < 8 && kingR + 1 < 9) {
                if(kingC + 1 == stoneC && kingR + 1 == stoneR) {
                    if(stoneC + 1 < 8 && stoneR + 1 < 9) {
                        kingC++; kingR++; stoneC++; stoneR++; continue;
                    }
                    else continue;
                }
                kingC++; kingR++;
            }
        }
        else if(moveDir[i] == "LT") {
            if(kingC - 1 >= 0 && kingR + 1 < 9) {
                if(kingC - 1 == stoneC && kingR + 1 == stoneR) {
                    if(stoneC - 1 >= 0 && stoneR + 1 < 9) {
                        kingC--; kingR++; stoneC--; stoneR++; continue;
                    }
                    else continue;
                }
                kingC--; kingR++;
            }
        }
        else if(moveDir[i] == "RB") {
            if(kingC + 1 < 8 && kingR - 1 >= 1) {
                if(kingC + 1 == stoneC && kingR - 1 == stoneR) {
                    if(stoneC + 1 < 8 && stoneR - 1 >= 1) {
                        kingC++; kingR--; stoneC++; stoneR--; continue;
                    }
                    else continue;
                }
                kingC++; kingR--;
            }
        }
        else if(moveDir[i] == "LB") {
            if(kingC - 1 >= 0 && kingR - 1 >= 1) {
                if(kingC - 1 == stoneC && kingR - 1 == stoneR) {
                    if(stoneC - 1 >= 0 && stoneR - 1 >= 1) {
                        kingC--; kingR--; stoneC--; stoneR--; continue;
                    }
                    else continue;
                }
                kingC--; kingR--;
            }
        }
    }
    output();
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();
    initialization();
    move();
}