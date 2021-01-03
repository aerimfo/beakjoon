// [10090] Counting Inversions
// https://www.acmicpc.net/problem/10090

#include <iostream>
using namespace std;

int ans[1000001], arr[1000001];
long long cnt = 0;

void mergeSort(int start, int end)
{
    if(start >= end) return;

    int mid = (start + end)/2;
    int i = start, j = mid+1, k = start;
    mergeSort(start, mid); 
    mergeSort(mid+1, end);

    while(i <= mid || j <= end) {
        // 왼쪽 배열의 수가 더 작은 경우
        if(j > end || (i <= mid && arr[i] <= arr[j])) {
            ans[k++] = arr[i++];
        }
        // 오른쪽 배열의 수가 더 작은 경우(inversion)
        // 왼쪽 배열에 있는 수는 오른쪽 배열의 수보다 모두 작음
        else {
            ans[k++] = arr[j++];
            cnt += mid-i+1; // 왼쪽 배열에 남아있던 모든 원소의 개수
        }
    }

    for(int i = start ; i <= end ; i++) {
        arr[i] = ans[i];
    }
}

int main(void)
{
    int n, tmp;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    mergeSort(0, n-1);
    
    cout << cnt << '\n';
    return 0;
}