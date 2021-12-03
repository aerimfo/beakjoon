// [10872] 팩토리얼
// https://www.acmicpc.net/problem/10872

#include <iostream>
using namespace std;

int n;

void input()
{
    cin >> n;    
}

int factorial()
{
    int ans = 1;
    for(int i = n; i > 0; i--) {
        ans *= i;
    }

    return ans;
}

int main(void)
{
    input();
    cout << factorial() << '\n';
}