/*[1668] 트로피 진열*/
/*https://www.acmicpc.net/problem/1668*/
/*22line에서 j=n, j>0으로 설정했더니 틀림 -> n개의 수를 입력받으면 배열의 가장 마지막 인덱스는 n-1^^*/

#include <stdio.h>
#define MAX 50

int main(void)
{
	int n; /*트로피 개수*/
	int trophy[MAX], left = 0, right = 0;
	int left_h = 0, right_h = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &trophy[i]);
	for (int i = 0; i < n; i++) /*왼쪽에서 볼 때*/
		if (trophy[i] > left_h)
		{
			left++;
			left_h = trophy[i];
		}
	for (int j = n - 1; j >= 0; j--) /*오른쪽에서 볼 때*/
		if (trophy[j] > right_h)
		{
			right++;
			right_h = trophy[j];
		}
	printf("%d\n", left);
	printf("%d", right);
}