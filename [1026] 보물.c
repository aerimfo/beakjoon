/*[1026] 보물*/

#include <stdio.h>
#define MAX 50

void bubble_sort(int list[], int n);
void reverse(int *b, int n);

int main(void)
{
	int n;
	int a[MAX], b[MAX];
	int sum = 0; /*s의 최솟값*/
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) /*A*/
		scanf_s("%d", &a[i]);
	for (int i = 0; i < n; i++) /*B*/
		scanf_s("%d", &b[i]);
	bubble_sort(a, n);
	bubble_sort(b, n);
	reverse(b, n);
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];
	printf("%d", sum);
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

void reverse(int *b, int n)
{
	char temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = b[i];
		b[i] = b[(n - 1) - i];
		b[(n - 1) - i] = temp;
	}
}