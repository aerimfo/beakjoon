#include <stdio.h>
int main(void)
{
	int n1, n2, x, num;
	int arr[10000];
	scanf("%d %d", &n1, &x);

	for (n2 = 0; n2 < n1; n2++)
	{
		scanf("%d", &num);
		arr[n2] = num;
	}

	for (int i = 0; i < n1; i++)
	{
		if (arr[i] < x)
			printf("%d ", arr[i]);
	}
	return 0;
}