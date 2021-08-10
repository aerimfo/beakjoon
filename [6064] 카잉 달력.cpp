// [6064] 카잉 달력
// https://www.acmicpc.net/problem/6064
// 수학, 정수론, 중국인의 나머지 정리
// 마지막 해 = m, n의 최소공배수
// 1부터 증가하는 방식으로 비교 -> 시간초과
// x값이 같은 해 vs y값이 같은 해

#include <iostream>
using namespace std;

int gcd(int a, int b) // 최대공약수 
{ 
    return (a % b)!=0 ? gcd(b, a % b) : b; // 유클리드 호제법 
} 

int lcm(int a, int b) // 최소공배수 
{ 
    return a * b / gcd(a, b); 
}


int cal(int m, int n, int x, int y, int lastYear)
{
    int i = 0, j = 0;
    while(x + m*i <= lastYear && y + n*j <= lastYear) {
        if(x + m*i < y + n*j) {
            i++;
        }
        else if(x + m*i > y + n*j) {
            j++;
        }
        else { // x값이 같아지는 해 = y값이 같아지는 해
            return x + m*i;
        }
    }
    return -1; // 해를 찾지 못한 경우
}

int main(void)
{
    int t, m, n, x, y, lastYear;
    cin >> t;
    while(t--) {
        cin >> m >> n >> x >> y;
        lastYear = lcm(m, n);
        cout << cal(m, n, x, y, lastYear) << '\n';
    }
}