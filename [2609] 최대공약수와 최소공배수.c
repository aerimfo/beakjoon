/*최대공약수와 최소공배수*/

#include <stdio.h>
int gcd(int a, int b) /*최대공약수 -> 유클리드 호제법*/
{
	return (a % b) != 0 ? gcd(b, a%b) : b;
}

int lcm(int a, int b) /*최소공배수*/
{
	return a * b / gcd(a, b); /*최소공배수 * 최대공약수 = a * b*/
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > b)
	{
		printf("%d", gcd(a, b));
		printf("\n");
		printf("%d", lcm(a, b));
	}
	else
	{
		printf("%d", gcd(a, b));
		printf("\n");
		printf("%d", lcm(b, a));
	}
}