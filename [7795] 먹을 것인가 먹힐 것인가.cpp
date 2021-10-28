// [7795] 먹을 것인가 먹힐 것인가
// https://www.acmicpc.net/problem/7795
// 이분 탐색

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a, b;

int binarySearch(int num)
{
    int left = 0, right = a.size() - 1, mid, cnt = 0;

    while(left <= right) {
        mid = (left + right) / 2;   
        if(a[mid] <= num) {
            left = mid + 1;
        }
        else {
            if(a[mid - 1] <= num) {
                return a.size() - mid;
            }
            else {
                right = mid - 1;
            }
        } 
    }
    return 0;
}

void output()
{
    int sum = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < b.size(); i++) {
        sum += binarySearch(b[i]);
    }
    cout << sum << '\n';
}

void input()
{
    int t, n, m, tmp;
    cin >> t;
    while(t--) {
        a.clear(); b.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int i = 0; i < m; i++) {
            cin >> tmp;
            b.push_back(tmp);
        }
        output();
    }
}

int main(void)
{
    input();
}