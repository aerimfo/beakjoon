// [1655] 가운데를 말해요
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(i == 0) {
            maxHeap.push(num);
            cout << num << '\n';
            continue;
        }

        if(num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}