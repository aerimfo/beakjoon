// [2675] 문자열 반복
// https://www.acmicpc.net/problem/2675

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t) {
        int r;
        char word[20];
        scanf("%d %s", &r, word);
        for(int i = 0 ; word[i] != 0 ; i++) {
            for(int j = 0 ; j < r ; j++) {
                printf("%c", word[i]);
            }
        }
        printf("\n");
        t--;
    }
}