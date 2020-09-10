// [3052] 나머지
// https://www.acmicpc.net/problem/3052

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int cnt = 1, n, tmp;
    vector <int> num;
    for(int i = 0 ; i < 10 ; i++) {
        scanf("%d", &n);
        num.push_back(n % 42);
    }
    sort(num.begin(), num.end());
    tmp = num[0];
    for(int i = 1 ; i < 10 ; i++) {
        if(num[i] != tmp) {
            cnt++;
            tmp = num[i];
        }
    }
    printf("%d\n", cnt);
}