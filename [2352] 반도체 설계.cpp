// [2352] 반도체 설계
// https://www.acmicpc.net/problem/2352
// 다이나믹 프로그래밍, 그리디 알고리즘, LIS

#include <iostream>
#include <vector>
#include <algorithm> // lower_bound()

using namespace std;

int main(void)
{
    int n, port[40002], it;
    vector <int> sequence;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> port[i];
    }
    
    // dp 벡터의 시작 인덱스를 1로 만듦
    sequence.push_back(0); sequence.push_back(port[1]);
    for(int i = 2 ; i <= n ; i++) {
        if(port[i] > sequence[sequence.size() - 1]) {
            sequence.push_back(port[i]);
            continue;
        }
        // 1. sequence의 마지막 원소보다 port[i]가 크다면 sequence 벡터에서 적절한 위치를 찾고
        it = lower_bound(sequence.begin(), sequence.end(), port[i]) - sequence.begin();
        // 2. 덮어쓰기
        sequence[it] = port[i];
    }

    cout << sequence.size() - 1 << endl;
}