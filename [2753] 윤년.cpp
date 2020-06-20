// [2753] 윤년
// https://www.acmicpc.net/problem/2753

#include <cstdio>

int main(void)
{
    int year;
    scanf("%d", &year);
    if((year % 4 == 0) && (year % 100 != 0)) {
        printf("1");
    }
    else if(year % 400 == 0) {
        printf("1");
    }
    else {
        printf("0");
    }
    
}