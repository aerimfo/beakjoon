// [4779] 칸토어 집합
// https://www.acmicpc.net/problem/4779
// 분할 정복

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;

void cantor(int num)
{
    if(num == 0) {
        printf("-");
        return;
    }
    else {
        cantor(num - 1);
        for(int i = 0 ; i < pow(3, num - 1) ; i++) {
            printf(" ");
        }
        cantor(num - 1);
    }
}

int main(void)
{
    while (scanf("%d", &n) != EOF){
        cantor(n);
        printf("\n");
    }
}