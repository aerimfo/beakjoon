// [2960] 에라토스테네스의 체
// 수학, 구현, 정수론
#include <iostream>
using namespace std;

int n, k;
bool num[1001];

int solution()
{
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        num[i] = true;
    }
    for(int i = 2; i <= n; i++) {
        if(num[i] == true) {
            for(int j = i; j <= n; j += i) {
                if(num[j] == true) {
                    num[j] = false;
                    ans++;
                    if(ans == k) {
                        return j;
                    }
                }
            }
        }
    }
}

int main(void)
{
    cin >> n >> k;
    cout << solution() << '\n';
    return 0;
}