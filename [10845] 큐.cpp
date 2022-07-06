// [10845] 큐
// 자료구조, 큐
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, num;
    string instruction;
    queue<int> q;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> instruction;
        if(instruction == "push") {
            cin >> num;
            q.push(num);
        }
        else if(instruction == "pop") {
            if(!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << "-1\n";
        }
        else if(instruction == "size") {
            cout << q.size() << '\n';
        }
        else if(instruction == "empty") {
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(instruction == "front") {
            if(!q.empty()) cout << q.front() << '\n';
            else cout << "-1\n";
        }
        else {
            if(!q.empty()) cout << q.back() << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}