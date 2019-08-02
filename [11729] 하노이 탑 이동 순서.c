/*https://www.acmicpc.net/problem/11729 */

/*하노이 탑 이동순서*/
#include <stdio.h>
#include <math.h> /*pow()*/
void htower(int n, int a, int b);

int main(void)
{
	int n, count; /*장대의 개수, 이동 횟수*/
	scanf("%d", &n);
	count = pow(2, n) - 1;
	printf("%d\n", count);
	htower(n, 1, 3); /*n개의 원판을 1->3로 이동*/
}

void htower(int n, int a, int b)
{
	int c;

	if (n == 1) /*1개의 원판 남은 경우*/
		printf("%d %d\n", a, b);
	else
	{
		c = 6 - a - b;
		htower(n - 1, a, c); /*(n-1)개를 a->c 이동*/
		printf("%d %d\n", a, b);
		htower(n - 1, c, b); /*(n-1)개를 c->b 이동*/
	}
}