// [6588] 골드바흐의 추측
// 수학, 정수론, 소수 판정, 에라토스테네스의 체
#include <cstdio>
#include <cstring>
using namespace std;

bool isPrime[1000001];

void findPrimeNum()
{
    for(int i = 2; i * i < 1000000; i++) {
        if(isPrime[i] == true) {
            for(int j = i * i; j < 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solution(int num)
{
    int a = 3, b = num - 3;
    while(a <= b) {
        if(isPrime[a] && isPrime[b]) {
            if(a + b == num) {
                printf("%d = %d + %d\n", num, a, b);
                return;
            }
        }
        a += 2; b -= 2;
    }
    printf("Goldbach's conjecture is wrong.\n");
}

int main(void)
{
    int num;
    memset(isPrime, true, sizeof(isPrime));
    findPrimeNum();
    while(true) {
        scanf("%d", &num);
        if(num != 0) solution(num);
        else break;
    }
    return 0;
}