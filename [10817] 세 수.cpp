// [10817] 세 수
// https://www.acmicpc.net/problem/10817

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector <int> num;
    int tmp;
    for(int i = 0 ; i < 3 ; i++) {
        scanf("%d", &tmp);
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    printf("%d\n", num[1]);
}