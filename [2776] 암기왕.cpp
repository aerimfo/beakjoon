// [2776] 암기왕
// https://www.acmicpc.net/problem/2776
// 이분 탐색

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> note1, note2;

void binearySearch(int num)
{
    int left = 0, right = n - 1, mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if(note1[mid] == num) {
            cout << "1" << '\n';
            return;
        }
        else if(note1[mid] < num) left = mid + 1;
        else right = mid - 1;
    }
    cout << "0" << '\n';
}

void output(int m)
{
    sort(note1.begin(), note1.end());
    for(int i = 0; i < m; i++) {
        binearySearch(note2[i]);
    }
}

void input()
{
    int t, m, tmp;
    cin >> t;

    while(t--) {
        note1.clear(); note2.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            note1.push_back(tmp);
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> tmp;
            note2.push_back(tmp);
        }
        output(m);
    }
}

int main(void)
{
    input();
}