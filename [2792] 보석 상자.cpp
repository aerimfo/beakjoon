// [2792] 보석 상자
// https://www.acmicpc.net/problem/2792
// 이분 탐색

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, maxNum = 0;
vector <double> num;

void binarySearch()
{
    int left = 1, right = maxNum, mid, students = 0, ans;
    while(left <= right) {
        students = 0;
        mid = (left + right) / 2;
        for(int i = 0; i < m; i++) {
            students += (ceil)(num[i]/mid);
        }
        if(students <= n) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
}

void input()
{
    int tmp;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        maxNum = tmp > maxNum ? tmp : maxNum;
        num.push_back(tmp);
    }
}

int main(void)
{
    input();
    binarySearch();
}