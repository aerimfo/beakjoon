// [10972] 다음 순열
// https://www.acmicpc.net/problem/10972
// 수학, 조합론

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> num;

void find(int n)
{
    int cnt = 1;
    do
    {
        if(cnt == 2) { // 첫번째 경우는 입력받은 수열과 동일 -> 첫번째 경우는 건너뛰고 그 다음 수열 출력하도록
            for(int i = 0  ; i < n ; i++) {
                cout << num[i] << " ";
            }
            return;
        }
        cnt++;
    } while (next_permutation(num.begin(), num.end()));

    cout << "-1" << '\n'; // 사전순으로 마지막에 오는 순열인 경우
    return;
}

int main(void)
{
    int n, tmp;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }

    find(n);
    return 0;
}