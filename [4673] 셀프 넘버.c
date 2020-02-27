/* 셀프 넘버 */
#include <stdio.h>
int sn[10001];

int d(int n)
{
	int result = n;

	while (n != 0)
	{
		result += n % 10; /* 제일 끝자리 수부터 차례대로 더해줌 */
		n = n / 10;
	}
	return result;
}

int main(void)
{
	for (int i = 0; i < 10001; i++)
		sn[i] = 0; /*0으로 배열 초기화 후 생성자가 있는 수는 그 수를 저장*/

	for (int i = 1; i < 10001; i++)
	{
		int idx = d(i); /* ★★변수의 선언은 중괄호의 앞부분이면 어디든지 가능★★*/
		/* ★★d(i)를 바로 사용하지 않고 idx를 굳이 선언하는 이유?★★
		   ➜ d(i)를 바로 사용할 경우 d(1), d(2), d(4)...와 같이 진행되므로
		   중간중간 빠지는 i가 생김
		*/

		if (idx <= 10000)
			sn[idx] = 1;
	}

	for (int i = 1; i < 10001; i++) /*셀프 넘버 출력*/
		if (sn[i] == 0)
			printf("%d\n", i);
}