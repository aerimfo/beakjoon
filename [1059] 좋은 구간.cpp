// [1059] 좋은 구간
// https://www.acmicpc.net/problem/1059

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, n;
vector <int> arr;

void input()
{
    int num;
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> num;
        arr.push_back(num);
    }
    cin >> n;
}

void findGoodSection()
{
    int left, right;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < l; i++) {
        if(n == arr[i]) {
            cout << 0 << '\n';
            return;
        }
        if(n < arr[i]) {
            left = n - arr[i-1] - 1;
            right = arr[i] - n - 1;
            cout << left*right + left + right;
            return;
        }
    }
}

int main(void)
{
    input();
    findGoodSection();
}