// [17626] Four Squares
// https://www.acmicpc.net/problem/17626

#include <iostream>
#include <cmath>
using namespace std;

int n, dp[50001];

void input()
{
    cin >> n;
}

int getMinSquareNum(int num)
{
    int min = dp[1] + dp[num-1];
    
    for(int i = 2; i*i < num; i++) {
        if(dp[i*i] + dp[num-i*i] < min) {
            min = dp[i*i] + dp[num-i*i];
        }
    }
    return min;
}

int getAns()
{
    dp[1] = 1; dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        if(sqrt(i) - (int)sqrt(i) > 0) {
            dp[i] = getMinSquareNum(i);
        }
        else {
            dp[i] = 1;
        }
    }
    return dp[n];
}

int main(void)
{
    ios::sync_with_stdio(0); 
	cin.tie(0); 

    input();
    cout << getAns() << '\n';
}