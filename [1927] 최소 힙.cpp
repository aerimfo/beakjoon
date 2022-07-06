// [1927] 최소 힙
// 자료 구조, 우선순위 큐
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x != 0) pq.push(x);
        else {
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << "0\n";
        }
    }
    return 0;
}