/*https://www.acmicpc.net/problem/10828 */

/*스택*/
#include <stdio.h>
#include <string.h> /*strcmp()*/

#define STACK_SIZE 10000 /*★100으로 했더니 런타임 에러..★*/

int main(void)
{
	int stack[STACK_SIZE]; /*스택 형성*/
	int topn = -1;
	int n; /*명령의 수*/
	char input[10];
	int item; /*스택에 넣을 정수*/
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", input);
		if (!strcmp(input, "push"))
			scanf("%d", &stack[++topn]);
		else if (!strcmp(input, "pop"))
		{
			if (topn < 0) /*스택이 비어있음*/
				printf("-1\n");
			else
				printf("%d\n", stack[topn--]); /*스택의 가장 위에 있는 정수 출력 후 제거*/
		}
		else if (!strcmp(input, "size"))
			printf("%d\n", topn + 1);
		else if (!strcmp(input, "empty"))
		{
			if (topn < 0) /*스택이 비어있을 경우*/
				printf("1\n");
			else /*스택이 비어있지 않을 경우*/
				printf("0\n");
		}
		else if (!strcmp(input, "top"))
		{
			if (topn < 0)
				printf("-1\n");
			else
				printf("%d\n", stack[topn]); /*스택의 가장 위에 있는 정수 출력*/
		}
	}
}