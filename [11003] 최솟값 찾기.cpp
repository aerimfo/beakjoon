// [11003] 최솟값 찾기
// 슬라이딩 윈도우, 덱
#include <iostream>
#include <deque>
using namespace std;

int a[5000001];

void getD(int n, int l)
{
    deque<pair<int, int> >dq;
    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front().second <= i-l) { // 슬라이딩 윈도우 크기 초과
            dq.pop_front();
        } 
        /* 내가 추가하려는 원소(a[i]보다 현재 덱에 있는 마지막 원소가 더 큰 경우
         -> a[i]가 최솟값이 될때까지 a[i]보다 작은 수는 전부 버리기 */
        while(!dq.empty() && dq.back().first > a[i]) {
            dq.pop_back();
        }
        dq.push_back(make_pair(a[i], i));
        cout << dq.front().first << " ";
    }   
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    getD(n, l);
    
    return 0;
}