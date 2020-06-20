// [2523] 별 찍기 - 13
// https://www.acmicpc.net/problem/2523

#include <cstdio>

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= i ; j++) {
            printf("*");
        }
        printf("\n");
    }
    for(int i = n - 1 ; i > 0 ; i--) {
        for(int j = 1 ; j <= i ; j++) {
            printf("*");
        }
        printf("\n");
    }
}