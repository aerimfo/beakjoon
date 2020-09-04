// [10818] 최소, 최대
// https://www.acmicpc.net/problem/10818

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, tmp;
    vector <int> num;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &tmp);
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    printf("%d %d", num[0], num[n - 1]);
}