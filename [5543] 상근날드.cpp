// [5543] 상근날드
// https://www.acmicpc.net/problem/5543

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector <int> bugger;
    int tmp, coak1, coak2, minCoak;
    for(int i = 0 ; i < 3 ; i++) {
        scanf("%d", &tmp);
        bugger.push_back(tmp);
    }
    sort(bugger.begin(), bugger.end());
    scanf("%d %d", &coak1, &coak2);
    if(coak1 > coak2) {
        minCoak = coak2;
    }
    else {
        minCoak = coak1;
    }
    printf("%d\n", bugger[0] + minCoak - 50);
}