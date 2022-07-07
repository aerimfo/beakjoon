// [1644] 소수의 연속합
// 수학. 정수론, 투 포인터, 소수 판정, 에라토스테네스의 체
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool isPrime[4000001];
vector<long long> primeSum;

void findPrimeNum(int n)
{
    for(long long i = 2; i * i <= n; i++) {
        if(isPrime[i] == true) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    long long sum = 0;
    primeSum.push_back(0); // n이 소수인 경우 자기 자신도 정답으로 카운트하기 위해
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            sum += i;
            primeSum.push_back(sum);
        }
    }
}

void solution(int n)
{
    memset(isPrime, true, sizeof(isPrime));
    findPrimeNum(n);

    int l = 0, r = 0, ans = 0;
    long long sectionSum = 0;
    while(l <= r && r < primeSum.size()) {
        sectionSum = primeSum[r] - primeSum[l];
        if(sectionSum == n) {
            ans++; l++; // r++ 도 OK
        }
        else if(sectionSum < n) {
            r++;
        }
        else {
            l++;
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    solution(n);
    return 0;
}