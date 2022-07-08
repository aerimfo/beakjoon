// [11050] 이항 계수 1
// 수학, 구현, 조합론
#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, a = 1, b = 1;
    cin >> n >> k;
	for(int i = n; i > n - k; i--) a *= i;
	for(int i = 1; i <= k; i++) b *= i;

	cout <<  a / b << '\n';
    return 0;
}