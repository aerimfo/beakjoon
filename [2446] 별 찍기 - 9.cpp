// [2446] 별 찍기 - 9
// https://www.acmicpc.net/problem/2446

#include <cstdio>

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = n ; i > 0 ; i--) {
        for(int k = 0 ; k < n - i ; k++) {
            printf(" ");
        }
        for(int j = 1 ; j <= 2 * i - 1 ; j++) {
            printf("*");
        }
        printf("\n");
    }
    for(int i = 2 ; i <= n ; i++) {
        for(int k = 0 ; k < n - i ; k++) {
            printf(" ");
        }
        for(int j = 1 ; j <= 2 * i - 1 ; j++) {
            printf("*");
        }
        printf("\n");
    }
}