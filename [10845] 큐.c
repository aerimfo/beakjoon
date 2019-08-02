/*https://www.acmicpc.net/problem/10845 */

/*큐*/
#include <stdio.h>
#include <string.h> /*strcmp()*/

#define STACK_SIZE 10000

int main(void)
{
	int stack[STACK_SIZE]; /*스택 형성*/
	int front = -1, rear = -1;
	int n; /*명령의 수*/
	char input[10];
	int item; /*스택에 넣을 정수*/
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", input);
		if (!strcmp(input, "push"))
			scanf("%d", &stack[++rear]);
		else if (!strcmp(input, "pop"))
		{
			if (front == rear)
				printf("-1\n"); /*큐가 비어있음*/
			else
				printf("%d\n", stack[++front]);
		}
		else if (!strcmp(input, "size"))
			printf("%d\n", rear - front);
		else if (!strcmp(input, "empty"))
		{
			if (front == rear)
				printf("1\n"); /*큐가 비어있음*/
			else
				printf("0\n");
		}
		else if (!strcmp(input, "front"))
		{
			if (front == rear)
				printf("-1\n"); /*큐가 비어있음*/
			else
				printf("%d\n", stack[front + 1]);
		}
		else if (!strcmp(input, "back"))
		{
			if (front == rear)
				printf("-1\n");
			else
				printf("%d\n", stack[rear]);
		}
	}
}