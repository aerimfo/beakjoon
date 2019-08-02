/*[2751] 수 정렬하기2*/
/*https://www.acmicpc.net/problem/2751*/
#include <stdio.h>
#define MAX 1000000
void mergesort(int num[], int left, int right);
void merge(int num[], int left, int mid, int right);
int n;
int num[MAX];

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	mergesort(num, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", num[i]);
}

void mergesort(int num[], int left, int right)
{
	int mid;
	if (right > left) /*left==right, 즉 원소가 1개이면 종료*/
	{
		mid = (left + right) / 2; /*분할(divide)*/
		mergesort(num, left, mid); /*앞부분 리스트 정렬(conquer)*/
		mergesort(num, mid + 1, right); /*뒷부분 리스트 정렬(conquer)*/
		merge(num, left, mid + 1, right); /*정렬된 2개의 부분 배열 결합(combine)*/
	}
}

void merge(int num[], int left, int mid, int right) /*둘 중에 작은 값을 취해서 temp에 저장*/
{
	int left_end, num_elements, tmp_pos;
	int temp[MAX];
	left_end = mid - 1; /*왼쪽 segment중 가장 오른쪽 index*/
	tmp_pos = left;
	num_elements = right - left + 1; /*원소의 개수*/
	while ((left <= left_end) && mid <= right)
	{
		if (num[left] <= num[mid])
		{
			temp[tmp_pos] = num[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}
		else
		{
			temp[tmp_pos] = num[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}
	while (left <= left_end) /*첫 번째 segment에 남아있는 항목을 추가*/
	{
		temp[tmp_pos] = num[left];
		left += 1;
		tmp_pos += 1;
	}
	while (mid <= right)
	{
		temp[tmp_pos] = num[mid];
		mid += 1;
		tmp_pos += 1;
	}
	for (int i = 0; i < num_elements; i++) /*임시 배열 temp의 값을 원래 배열 num에 복사*/
	{
		num[right] = temp[right];
		right -= 1;
	}
}