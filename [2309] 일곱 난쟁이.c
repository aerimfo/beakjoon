/*[2309] ¿œ∞ˆ ≥≠¿Ô¿Ã*/
/*sum of 9 dwarfs -(sum of some two dwarfs) = 100*/
/*brute force algorithm : method of substituting all possible combinations one by one*/
/*https://www.acmicpc.net/problem/2309*/
#include <stdio.h>

int main(void)
{
	int temp, flag = 1;
	int height[9], sum = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height[i]);
		sum = sum + height[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (height[i] + height[j]) == 100)
			{
				height[i] = 0;
				height[j] = 0;
				flag = 0; /*to get out for gate twice*/
			}
		}
		if (!flag)
			break;
	}

	for (int i = 0; i < 8; i++) /*bubble sort*/
	{
		for (int j = 0; j < 8 - i; j++)
		{
			if (height[j] > height[j + 1])
			{
				temp = height[j];
				height[j] = height[j + 1];
				height[j + 1] = temp;
			}
		}
	}

	for (int i = 2; i < 9; i++) /*height[0], height[1] is 0*/
		printf("%d\n", height[i]);
}