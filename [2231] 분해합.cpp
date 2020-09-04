// [2231] 분해합
// https://www.acmicpc.net/problem/2231
// 브루트 포스

#include <cstdio>
#include <string> // to_string(int)
using namespace std;

int sumOfEachDigits(int m, int digits);

int main(void)
{
    int n, m, digits; 
    scanf("%d", &n);
    digits = to_string(n).size(); // n의 자리수
    m = n - 9 * digits; // 각 자리수 합의 최댓값은 각 자리수가 모두 9일 때

    while(m <= n) {
        if(m + sumOfEachDigits(m, digits) == n) {
            printf("%d\n", m);
            return 0;
        }
        m++;
    }
    printf("0\n");
}

int sumOfEachDigits(int m, int digits)
{   
    int sum = 0;
    while(digits) {
        sum += m % 10;
        m /= 10;
        digits--;
    }
    return sum;
}