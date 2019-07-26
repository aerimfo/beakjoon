/*[2444] º° Âï±â - 7*/
/*https://www.acmicpc.net/problem/2444*/
#include <stdio.h>
int main(void)
{
	int n, replay;
	scanf("%d", &n);

	/*triangle*/
	for (int i = 1; i <= n; i++)
	{
		replay = ((2 * n - 1) - (2 * i - 1)) / 2;
		for (int k = 0; k < replay; k++)
			printf(" ");
		for (int j = 0; j < 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}

	/*Inverted triangle*/
	for (int i = n - 1; i > 0; i--)
	{
		replay = ((2 * n - 1) - (2 * i - 1)) / 2;
		for (int k = 0; k < replay; k++)
			printf(" ");
		for (int j = 0; j < 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
}