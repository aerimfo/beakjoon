// [1183] 약속
// https://www.acmicpc.net/problem/1183

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> diff;

void input()
{
    int a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        diff.push_back(a - b);
    }   
}

void getT()
{
    int ans = 0;

    sort(diff.begin(), diff.end());
    if(n % 2 == 1) {
        ans = 1;
    }
    else {
        ans = diff[n/2] - diff[n/2 - 1] + 1;
    }
    cout << ans << '\n';
}

int main(void)
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    input();
    getT();
}