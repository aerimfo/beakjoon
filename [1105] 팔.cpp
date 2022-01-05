// [1105] 팔
// https://www.acmicpc.net/problem/1105

#include <iostream>
using namespace std;

string l, r;

void input()
{
    cin >> l >> r;
}

void find8num()
{
    int ans = 0;

    if(l.length() != r.length()) {
        cout << 0 << '\n';
    }
    else {
        for(int i = 0; i < l.length(); i++) {
            if(l[i] == r[i] && l[i] == '8') {
                ans++;
            }
            else if(l[i] != r[i]) {
                break;
            }
        }

        cout << ans << '\n';
    }
}

int main(void)
{
    input();
    find8num();
}