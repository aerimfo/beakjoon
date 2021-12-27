// [1021] 회전하는 큐
// https://www.acmicpc.net/problem/1021

#include <iostream>
#include <deque>
#include <algorithm> // find()
using namespace std;

int n, m, position[51], moveCnt = 0;
deque <int> q;

void input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> position[i];
    }
}

void makeQueue()
{
    for(int i = 1; i <= n; i++) {
        q.push_back(i);
    }
}

void moveLeftAndPop(int cnt)
{
    for(int i = 0; i < cnt; i++) {
        q.push_back(q[0]); q.pop_front();
    }
    
    q.pop_front();
}

void moveRightAndPop(int cnt)
{
    for(int i = 0; i < cnt; i++) {
        q.push_front(q[q.size() - 1]); q.pop_back();
    }

    q.pop_front();
}

int getMinOperations()
{
    int delPosition;

    for(int i = 0; i < m; i++) {
        delPosition = find(q.begin(), q.end(), position[i]) - q.begin();
        if(delPosition < q.size() - delPosition) {
            moveCnt += delPosition;
            moveLeftAndPop(delPosition);
        }
        else {
            moveCnt += (q.size() - delPosition);
            moveRightAndPop(q.size() - delPosition);
        }
    }

    return moveCnt;
}

int main(void)
{
    input();
    makeQueue();
    cout << getMinOperations() << '\n';
}