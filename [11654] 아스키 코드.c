/* 아스키 코드 */
#include <stdio.h>
int main(void)
{
	char n;
	scanf("%c", &n); /*n을 문자로 받음*/

	if ('0' <= n <= '9') /*n이 숫자일 경우*/
		printf("%d", n);
	else if ('A' <= n <= 'Z') /*n이 대문자일 경우*/
		printf("%d", 65 + n);
	else if ('a' <= n <= 'z') /*n이 소문자일 경우*/
		printf("%d", n + 97);
}