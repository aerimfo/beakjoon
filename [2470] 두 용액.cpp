// [2470] 두 용액
// https://www.acmicpc.net/problem/2470

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector <long long> property;

void input()
{
    int num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        property.push_back(num);
    }
}

void solve()
{
    sort(property.begin(), property.end());

    int left = 0, right = n - 1;
    long long sum = 0, lowNum = property[0], highNum = property[n-1], minSum = lowNum + highNum;

    while(left < right) {
        sum = property[left] + property[right];
        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            lowNum = property[left];
            highNum = property[right];
        }
        if(sum > 0) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << lowNum << ' ' << highNum << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}