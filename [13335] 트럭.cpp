// [13335] 트럭
// 구현, 시뮬레이션, 큐
#include <iostream>
#include <queue>
using namespace std;
 
int n, w, L, ans, a[1000];
queue<int> q;
 
void input()
{
    cin >> n >> w >> L;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solution()
{
    int weightSum = 0; // 다리 위의 트럭 무게의 합
    for(int i = 0; i < n; i++) {
        while(true) {
            if(q.size() == w) {
                weightSum -= q.front(); // 맨 앞의 트럭 제거
                q.pop();
            }
            if(a[i] + weightSum <= L) {
                break;
            }
            q.push(0); // 무게가 L을 넘는 경우
            ans++;
        }
        q.push(a[i]);
        weightSum += a[i];
        ans++;
    }
}

int main()
{
    input();
    solution();
    cout << ans + w; // 마지막 트럭이 건너는 시간(W) 추가
    return 0;
}