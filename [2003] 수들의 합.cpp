// [2003] 수들의 합
// 투 포인터
#include <iostream>
using namespace std;

int n, m, sum[10001];

void input()
{
    int num;
    cin >> n >> m;
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = sum[i-1] + num;
    }
}

int solution()
{
    int ans = 0;
    for(int i = 0; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(sum[j] - sum[i] == m) {
                ans++;
            }
        }
    }
    return ans;
}

int main(void)
{
    input();
    cout << solution() << '\n';
    return 0;
}