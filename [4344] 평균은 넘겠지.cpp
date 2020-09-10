// [4344] 평균은 넘겠지
// https://www.acmicpc.net/problem/4344

#include <stdio.h>

int main(void)
{
    int c, n;
    scanf("%d", &c);

    while(c) {
        // 학생 N명 점수, 점수 총합, 평균, 평균 이상인 학생들의 수 
        int score[1001], sum = 0, mean, cnt = 0;
        scanf("%d", &n);

        // 학생 N명의 점수 입력
        for(int i = 0 ; i < n ; i++) {
            scanf("%d", &score[i]);
            sum += score[i];
        }

        mean = sum / n;
        for(int i = 0 ; i < n ; i++) {
            if(score[i] > mean) {
                cnt++;
            }
        }

        // %를 출력하기 위해서는 %%로 해줘야 함
        // 결과를 소수점까지 출력하기 위해서는 cnt / n 값이 실수형 
        // -> cnt, n 모두 float 형으로 타입캐스팅 해준 후 연산
        printf("%.3f%%\n", (float)cnt / (float)n * 100);
        c--;
    }
}