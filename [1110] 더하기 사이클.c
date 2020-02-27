/* 더하기 사이클 */
#include <stdio.h>
int main(void)
{
	int n, n1, a, b, time = 0;
	scanf("%d", &n);
	n1 = n;

	do
	{
		if (n1 < 10) /*주어진 수가 10보다 작을 경우*/
		{
			a = 0, b = n1;
			n1 = b * 10 + (a + b) % 10;
			time++;
		}
		else
		{
			a = n1 / 10; /*a = 십의자리 수*/
			b = n1 % 10; /*b = 일의자리 수*/
			n1 = b * 10 + (a + b) % 10;
			time++;
		}
	} while (n1 != n);
	printf("%d\n", time);
}