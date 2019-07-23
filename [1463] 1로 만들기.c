/*[1463] 1로 만들기*/
/*https://www.acmicpc.net/problem/1463*/
/*Visual Studio's default stack size is 1MB, so if you allocate large memory, 
  declare it as a global variable.*/
#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
int dp[1000001] = { 0 }; /*The minimum number of operations to create as 1*/

int main(void)
{
	int n;
	scanf("%d", &n);
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		/*'+1' = operation is performed once*/
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i-1], dp[i / 2]) + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i-1], dp[i / 3]) + 1;
	}
	printf("%d", dp[n]);
}