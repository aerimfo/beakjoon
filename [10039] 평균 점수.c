/* 평균 점수 */
#include <stdio.h>
int main(void)
{
	int sum = 0;
	int score[5], n = 0;;

	for (int i = 0; i < 5; i++)
		scanf("%d", &score[i]); /*scanf()로 수를 입력받고 배열에 저장하는 것까지 한번에 가능*/

	for (int i = 0; i < 5; i++)
	{
		if (40 <= score[i])
			sum += score[i];
		else
			sum += 40;
	}
	printf("%d", sum / 5);
}