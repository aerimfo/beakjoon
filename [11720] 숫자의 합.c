// [11720] 숫자의 합
// https://www.acmicpc.net/problem/11720

#include <stdio.h>

int main(void)
{
    int n, sum = 0;
    char arr[101];
    scanf("%d", &n);
    scanf("%s", arr);
    for (int i = 0; i < n; i++) {
        sum += arr[i] - '0';
    }
    printf("%d", sum);
}