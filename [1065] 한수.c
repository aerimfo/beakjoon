/*[1065] 한수*/

#include <stdio.h>
int main(void)
{
	int n, count = 0; /*자연수 n, 한수의 개수*/
	int a = 0, b = 0, c = 0;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (i <= 99)
			count++;
		else
		{
			a = i / 100; /*백의 자리*/
			b = (i - a * 100) / 10; /*십의 자리*/
			c = i - a * 100 - b * 10; /*일의 자리*/
			if ((b - a) == (c - b))
				count++;
		}
	}
	printf("%d\n", count);
}