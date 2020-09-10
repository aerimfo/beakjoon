// [2562] 최댓값
// https://www.acmicpc.net/problem/2562

#include <cstdio>

int main(void)
{
    int max = 0, idx, num[10];
    for(int i = 1 ; i <= 9 ; i++) {
        scanf("%d", &num[i]);
        if(num[i] > max) {
            max = num[i];
            idx = i;
        }
    }
    printf("%d\n%d\n", max, idx);
}