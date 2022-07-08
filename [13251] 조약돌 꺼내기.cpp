// [13251] 조약돌 꺼내기
// 수학, 조합
// 확률을 구하는 것 -> 분모 분자에 공통으로 들어가는 k!은 생략 OK
#include <cstdio>
using namespace std;

int m, totalStone, color[51];

void solution(int k)
{
    double a = 0, b = 1, tmp = 0;
    for(int i = 0; i < m; i++) {
        tmp = 1;
        for(int j = 0; j < k; j++) {
            tmp *= (color[i] - j);
        }
        a += tmp;
    }
    for(int j = 0; j < k; j++) {
        b *= (totalStone - j);
    }
    printf("%.18lf\n", a / b);
}

int main(void)
{
    int k;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &color[i]);
        totalStone += color[i];
    }
    scanf("%d", &k);
    solution(k);
    return 0;
}