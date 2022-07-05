// [7453] 합이 0인 네 정수
// 정렬, 이분 탐색, 투 포인터
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[4001], b[4001], c[4001], d[4001];
vector<long long> ab, cd;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
}

void solution()
{
    int l = 0, r = n*n-1;
    long long ans = 0, sameAB = 1, sameCD = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    while(l < n*n && r >= 0) {
        if(ab[l] + cd[r] == 0) {
            for(int i = l + 1; i < n*n; i++) {
                if(ab[i] == ab[l]) sameAB++;
                else break;
            }
            for(int i = r - 1; i >= 0; i--) {
                if(cd[i] == cd[r]) sameCD++;
                else break;
            }
            ans += sameAB * sameCD;
            l += sameAB; r -= sameCD;
            sameAB = 1; sameCD = 1;
        }
        else if(ab[l] + cd[r] < 0) {
            l++;
        }
        else {
            r--;
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solution();
    return 0;
}