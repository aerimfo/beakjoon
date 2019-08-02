/*[11651] 좌표 정렬하기2*/
#include <stdio.h>
#define MAX 100000

typedef struct twodimen
{
	int x;
	int y;
}twod;

void swap(twod arr[], int a, int b);
int partition(twod arr[], int left, int right);
void quicksort(twod arr[], int left, int right);

int main(void)
{
	int n; /*점의 개수*/
	twod dot[MAX];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d %d", &dot[i].x, &dot[i].y);
	quicksort(dot, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", dot[i].x, dot[i].y);
}

void swap(twod arr[], int a, int b)
{
	twod temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int partition(twod arr[], int left, int right)
{
	int pivot = left;
	int low = left + 1;
	int high = right;

	while (low <= high) /*교차되기 전까지 반복*/
	{
		while (arr[pivot].y >= arr[low].y) /*pivot보다 큰 값을 찾는 과정*/
		{
			if (arr[pivot].y == arr[low].y)
			{
				if (arr[pivot].x > arr[low].x)
					low++;
				else
					break; /*★핵심★*/
			}
			else
				low++;
		}
		while (arr[pivot].y <= arr[high].y) /*pivot보다 작은 값을 찾는 과정*/
		{
			if (arr[pivot].y == arr[high].y)
			{
				if (arr[pivot].x < arr[high].x)
					high--;
				else
					break; /*★핵심★*/
			}
			else
				high--;
		}
		if (low <= high) /*교차되지 않은 상태이면 swap*/
			swap(arr, low, high);
	}
	swap(arr, left, high); /*pivot과 high교환*/
	return high;  /*옮겨진 pivot의 위치정보 반환*/

}

void quicksort(twod arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1); /*왼쪽정렬*/
		quicksort(arr, pivot + 1, right); /*오른쪽정렬*/
	}
}