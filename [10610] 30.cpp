// [10610] 30
// 그리디 알고리즘, 정수론

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    string n;
    int sum = 0;
    cin >> n;
    sort(n.begin(), n.end());
    for(int i = 0 ; i < n.size() ; i++) {
        sum += n[i] - '0';
    }

    // 1. 일의 자리를 0으로 만들 수 있는지 확인(0이 있는지 확인)
    if(n[0] == '0') {
        // 2. 3의 배수인지 확인
        if(sum % 3 == 0) {
            for(int i = n.size() - 1 ; i >= 0 ; i--) {
                cout << n[i];
            }
        }
        else {
            cout << -1 << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
}