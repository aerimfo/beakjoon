/*[2750] 수 정렬하기*/
#include <stdio.h>
#define MAX 1000

void bubble_sort(int list[], int n);

int main(void)
{
	int n, num;
	int ascend[MAX];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);
		ascend[i] = num;
	}
	bubble_sort(ascend, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d", ascend[i]);
		printf("\n");
	}
}

void bubble_sort(int list[], int n)
{
	int flag = 1, temp;
	for (int i = n - 1; flag > 0; i--)
	{
		flag = 0;
		for (int j = 0; j < i; j++)
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				flag = 1;
			}
	}
}