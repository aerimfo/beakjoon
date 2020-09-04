// [1049] 기타줄
// https://www.acmicpc.net/problem/1049
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n, m, tmp1, tmp2;
    vector<int> pack;
    vector<int> piece;
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < m ; i++) {
        cin >> tmp1 >> tmp2;
        pack.push_back(tmp1); piece.push_back(tmp2);
    }

    sort(pack.begin(), pack.end());
    sort(piece.begin(), piece.end());

    // 모두 낱개로 사는게 제일 싼 경우
    if(pack[0] > 6 * piece[0]) { 
        cout << piece[0] * n; 
    }

    // 팩으로 최대한 사고 남은 것은 낱개로 사는 경우 vs 모두 팩으로 사는 경우
    else {
        cout << min((n / 6) * pack[0] + (n % 6) * piece[0], (int)ceil((double)n/6) * pack[0]) << endl;
    }
    return 0;
}