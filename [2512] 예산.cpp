// [2512] 예산
// https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int start(int , int, int);
vector <int> request; // 각 지방의 예산요청 금액

int main(void)
{
    int n, money; // 지방의 수
    int max = 0, total = 0; // 상한액, 국가예산 총액
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> money;
        request.push_back(money);
    }
    cin >> total;
    sort(request.begin(), request.end());
    max = request[n-1]; // !!최초 상한액은 지방 예산요청 중 최댓값으로 설정!!
    cout << start(n, max, total) << endl;
}

int start(int n, int max, int total)
{
    int sum;
    while(true) {
        sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += (max > request[i] ? request[i] : max);
        }
        if(sum <= total) {
            return max;
        }
        else {
            max--;
        }
    }
    return max;
}