// [11720] 숫자의 합
// https://www.acmicpc.net/problem/11720

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int n, sum = 0;
    string s;
    cin >> n >> s;
    for(int i = 0 ; i < n ; i++) {
        sum += s[i] - '0';
    }
    printf("%d\n", sum);
}