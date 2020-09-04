// [2588] 곱셈
// https://www.acmicpc.net/problem/2588

#include <cstdio>
using namespace std;

int main(void)
{
    int num1, num2, num3, num4, num5, num6;
    scanf("%d %d", &num1, &num2);
    num3 = num1 * (num2 % 10);
    num4 = num1 * ((num2 % 100) / 10);
    num5 = num1 * (num2 / 100);
    num6 = (num5 * 100) + (num4 * 10) + num3;
    printf("%d\n%d\n%d\n%d\n", num3, num4, num5, num6);
}