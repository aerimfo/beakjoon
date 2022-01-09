// [1080] 행렬
// https://www.acmicpc.net/problem/1080

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int n, m;
bool a[51][51];
bool b[51][51];

void input()
{
    string s;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            a[i][j] = (s[j] == '0') ? 0 : 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            b[i][j] = (s[j] == '0') ? 0 : 1;
        }
    }
}

void XOR(int y, int x)
{
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            a[i][j] = 1 - a[i][j];
        }
    }
}

bool checkSameness()
{
    bool same = true;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] != b[y][x]) {
                return false;
                break;
            }
        }
    }

    return true;
}

void getMinOperation()
{
    int ans = 0;
    bool change = false;

    if (n >= 3 && m >= 3) {
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (a[i][j] != b[i][j]) {
                    XOR(i, j);
                    ans++;
                }

                if (checkSameness() == true) {
                    change = true;
                    break;
                }
            }

            if(change) 
                break;
        }
    }
    else {
        change = true;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (a[y][x] != b[y][x]) {
                    change = false;
                }
            }
        }
    }

    if (change)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
}
 
int main(void)
{
    input();
    getMinOperation();
}