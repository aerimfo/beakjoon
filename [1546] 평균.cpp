// [1546] 평균
// https://www.acmicpc.net/problem/1546

#include <cstdio>
using namespace std;

int main(void)
{
    int n, tmp, m = 0;
    double sum = 0, score[1001];

    scanf("%d", &n);

    // 원래 점수
    for(int i = 0 ; i < n ; i++) {
        scanf("%lf", &score[i]);
        if(score[i] > m) {
            m = score[i];
        }
    }

    // 고친 점수
    for(int i = 0 ; i < n ; i++) {
        score[i] = score[i] / m * 100;
        sum += score[i];
    }

    printf("%lf\n", sum / n);
}