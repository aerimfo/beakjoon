/* »ó¼ö */
#include <stdio.h>
int main(void)
{
	int a[3], b[3], n = 1;
	int a2 = 0, b2 = 0;

	for (int i = 0; i < 3; i++)
		a[i] = getchar();

	getchar();

	for (int i = 0; i < 3; i++)
		b[i] = getchar();

	for (int i = 0; i < 3; i++)
	{
		a2 += n * (a[i] - 48);
		b2 += n * (b[i] - 48);
		n *= 10;
	}

	if (a2 > b2)
		printf("%d\n", a2);
	else
		printf("%d\n", b2);

	return 0;
}