// [10819] 차이를 최대로
// https://www.acmicpc.net/problem/10819
// 브루트포스, 백트래킹

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> num;

int maxGap(int n)
{
    int sum = 0, gap = 0, maxSum = 0;;
    do
    {
        sum = 0;
        for(int i = 0 ; i < n - 1 ; i++) {
            gap = num[i] > num[i + 1] ? num[i] - num[i + 1] : num[i + 1] - num[i];
            sum += gap;
        }
        if(sum > maxSum) maxSum = sum;
    } while (next_permutation(num.begin(), num.end()));

    return maxSum;
}

int main(void)
{
    int n, tmp;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end()); 
    cout << maxGap(n) << '\n';
    return 0;
}