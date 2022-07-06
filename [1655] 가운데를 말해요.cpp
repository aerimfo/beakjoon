// [1655] 가운데를 말해요
// 자료구조, 우선순위 큐
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, num;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(minHeap.size() == maxHeap.size()) maxHeap.push(num);
        else minHeap.push(num);

        if(!maxHeap.empty() && !minHeap.empty()) {
            if(maxHeap.top() > minHeap.top()) {
                int minTop = minHeap.top(); minHeap.pop();
                int maxTop = maxHeap.top(); maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(minTop);
            }
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}