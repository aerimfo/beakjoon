// [1292] 쉽게 푸는 문제
// https://www.acmicpc.net/problem/1292

#include <iostream>
#include <vector>
using namespace std;

int a, b;
vector <int> arr;

void input()
{
    cin >> a >> b;
}

void makeArray()
{
    arr.push_back(0);
    int num = 1, cnt = 0;
    
    while(cnt <= b) {
        for(int i = 0 ; i < num ; i++) {
            arr.push_back(num);  
            cnt++;    
        }
        num++;
    }
}

int makeSum()
{
    int ans = 0;

    for(int i = a ; i <= b ; i++) {
        ans += arr[i];
    }
    return ans;
}

int main(void)
{
    input();
    makeArray();
    cout << makeSum() << '\n';

    return 0;
}