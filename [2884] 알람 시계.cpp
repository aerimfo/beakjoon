// [2884] 알람 시계
// https://www.acmicpc.net/problem/2884

#include <cstdio>

int main(void)
{
    int h, m;
    scanf("%d %d", &h, &m);
    if(m < 45) {
        m = (m + 60) - 45;
        if(h == 0) {
            h = (h + 24) - 1;
        }
        else {
            h -= 1;
        }
    }
    else {
        m -= 45;
    }
    printf("%d %d", h, m);
}