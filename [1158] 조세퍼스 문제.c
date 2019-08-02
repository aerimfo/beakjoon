/*https://www.acmicpc.net/problem/1158 */

/* [1158] 조세퍼스 문제 */
/* 배열 초기화에서 for문 사용하면 시간 초과 */

#include <stdio.h>
#define MAX 5001

void joseph_f();

int main()
{
	joseph_f();
}
void joseph_f()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int j = 1;
	int joseph[MAX] = { 0, }; // 배열 전체 0으로 초기화
	int time;

	printf("<");
	for (int i = 0; i < n; i++)
	{
		time = 0;
		while (1)
		{
			if (joseph[j] == 0) //값이 0인 순간부터 1, 2, 3....
				time++;
			if (time == k)
			{
				joseph[j] = 1;
				if (i == n - 1) // 한 사람만 남은 경우
					printf("%d>", j);
				else // 두 사람 이상 남은 경우
					printf("%d, ", j);
				break;
			}
			j++;
			if (j > n)
				j = 1;
		}

	}
}