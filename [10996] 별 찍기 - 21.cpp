// [10996] 별 찍기 - 21
// https://www.acmicpc.net/problem/10996

#include <cstdio>
#include <cmath>

int main(void)
{
    double n;
    scanf("%lf", &n);
    for(int i = 1 ; i <= n ; i++) {
        printf("*");
        for(int j = 0 ; j < ceil(n / 2) - 1 ; j++) {
            printf(" *");
        }
        printf("\n");
        for(int j = 0 ; j < floor(n / 2) ; j++) {
            printf(" *"); 
        }
        printf("\n");
    }
}