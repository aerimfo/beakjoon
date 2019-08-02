/*[1427] 소트인사이드*/
/*https://www.acmicpc.net/problem/1427*/
#include <stdio.h>
#include <string.h> /*strlen()*/
#define MAX 100000

void bubble_sort(char *n);
char n[MAX];

int main()
{
	scanf("%s", n); /*strlen() 사용하기 위해서 %s로 입력*/
	bubble_sort(n);
	printf("%s", n);
}

void bubble_sort(char *n) /*내림차순 정렬*/
{
	int i, j;
	int len = strlen(n);
	char temp;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - (i + 1); j++)
		{
			if (n[j] < n[j + 1])
			{
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
}
