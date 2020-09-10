// [15953] 상금 헌터
// https://www.acmicpc.net/problem/15953

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int t, a = 0, b = 0; // testcase
    int first[7] = {0, 500, 300, 200, 50, 30, 10};
    int second[6] = {0, 512, 256, 128, 64, 32};
    
    cin >> t;
    while(t--) {
        int sum = 0;
        cin >> a >> b;

        // 2017년도
        // 진출하지 못함
        if(a <= 0 || a > 21) {
            a = 0;
        }
        else {
            for(int i = 1 ; i <= 6 ; i++) {
                if(a <= i * (i+1) / 2) {
                    sum += first[i];
                    break;
                }
            }
        }

        // 2018년도
        // 진출하지 못함
        if(b <= 0 || b > 31) {
            b = 0;
        }
        else {
            for(int i = 1 ; i <= 5 ; i++) {
                if(b <= pow(2, i) - 1) {
                    sum += second[i];
                    break;
                }
            }
        }
        cout << sum * 10000 << '\n';
    }

    return 0;
}