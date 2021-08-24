// [10974] 모든 순열
// https://www.acmicpc.net/problem/10974
// 브루트포스

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> num;

void perm(int n)
{
    do
    {
        for(int i = 0 ; i < n ; i++) {
            cout << num[i] << " ";
        }
        cout << '\n';
    } while (next_permutation(num.begin(), num.end()));
}

int main(void)
{
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++) {
        num.push_back(i);
    }

    perm(n);
    return 0;
}