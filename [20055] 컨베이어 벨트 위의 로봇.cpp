// [20055] 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector <int> a;
vector <bool> robot;

void input()
{
    int num;
    cin >> n >> k;
    for(int i = 1; i <= 2*n; i++) {
        cin >> num;
        a.push_back(num);
        robot.push_back(false);
    }
}

bool isPossibleToMove(int pos)
{
    if(robot[pos] == false && a[pos] >= 1) {
        return true;
    }
    return false;
}

void solve()
{
    int level = 0;
    while(true) {
        level++;
        // 1번
        rotate(a.begin(), a.begin() + 2*n-1, a.end());
        rotate(robot.begin(), robot.begin() + 2*n-1, robot.end());
        for(int i = n-1; i < 2*n; i++) {
            if(robot[i] == true) {
                robot[i] = false;
            }
        }

        // 2번
        for(int i = n-2; i >= 0; i--) {
            if(robot[i] == true) {
                if(isPossibleToMove(i+1)) {
                    robot[i] = false;
                    a[i+1]--;
                    if(i+1 != n-1) {
                        robot[i+1] = true;
                    }
                }
            }
        }

        // 3번
        if(a[0] != 0) {
            robot[0] = true;
            a[0]--;
        }

        // 4번
        int zeroDurabilitySpace = 0;
        for(int i = 0; i < 2*n; i++) {
            if(a[i] == 0) {
                zeroDurabilitySpace++;
            }
        }  
        if(zeroDurabilitySpace >= k) {
            break;
        }
    }
    cout << level << '\n';
}

int main(void)
{
    input();
    solve();
}