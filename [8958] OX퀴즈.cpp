// [8958] OX퀴즈
// https://www.acmicpc.net/problem/8958

#include <iostream>
#include <string>
using namespace std;

int run(string result)
{
    int cnt = 0, sum = 0;
    for(int i = 0 ; i < result.size() ; i++) {
        if(result[i] == 'O') {
            cnt++;
            sum += cnt;
        }
        else if(result[i] == 'X') {
            cnt = 0;
        }
    }
    return sum;
}

int main(void)
{
    int t; 
    string result;
    cin >> t;
    while(t) {
        cin >> result;
        cout << run(result) << '\n';
        t--;
    }
}