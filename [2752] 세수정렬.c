/*[2752] 세수정렬*/
#include <stdio.h>

void bubble_sort(int list[], int n);
int main(void)
{
	int num;
	int ascend[3];
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &num);
		ascend[i] = num;
	}
	bubble_sort(ascend, 3); /*오름차순으로 정렬*/
	for (int i = 0; i < 3; i++)
		printf("%d ", ascend[i]);
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