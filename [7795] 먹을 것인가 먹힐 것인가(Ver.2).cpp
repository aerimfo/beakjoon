// [7795] 먹을 것인가 먹힐 것인가
// 정렬, 투 포인터
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B;

int solution(int n, int m)
{
    int a = n, b = m, ans = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while(true) {
        if(a < 1 || b < 1) {
            break;
        }
        if(A[a] > B[b]) {
            ans += b;
            a--;
        }
        else {
            b--;
        }
    }

    return ans;
}

void initialization()
{
    A.clear(); B.clear();
    A.push_back(0); B.push_back(0);
}

int main(void)
{
    int t, n, m, num;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        initialization();
        for(int i = 0; i < n; i++) {
            scanf("%d", &num);
            A.push_back(num);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &num);
            B.push_back(num);
        }
        printf("%d\n", solution(n, m));
    }
}