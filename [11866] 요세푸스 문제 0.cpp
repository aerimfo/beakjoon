// [11866] 요세푸스 문제 0
// https://www.acmicpc.net/problem/11866

#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue <int> arr, ans;

void input()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        arr.push(i);
    }
}

void findJosephus()
{
    int cnt = 0;
    while(!arr.empty()) {
        for(int i = 0; i < arr.size(); i++) {
            cnt++;
            if(cnt == k) {
                ans.push(arr.front());
                arr.pop();
                cnt = 0;
                break;
            }
            else {
                arr.push(arr.front());
                arr.pop();
            }
        }
    }
}

void output()
{
    cout << '<';
    while(!ans.empty()) {
        if(ans.size() != 1) {
            cout << ans.front() << ", ";
        }
        else {
            cout << ans.front();
        }
        ans.pop();
    }
    cout << '>';
}

int main(void)
{
    input();
    findJosephus();
    output();
}