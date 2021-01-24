// [1339] 단어 수학
// https://www.acmicpc.net/problem/1339
// greedy

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int change[27] = {0,}; // A~Z

bool desc(int a, int b){ 
    return a > b; 
} 

// ex) ABC = 100A + 10B + C -> change[0] = 100, change[1] = 10, change[2] = 1
void init(string s)
{
    for(int i = 0 ; i < s.size() ; i++) {
        change[s[i]-65] += pow(10, s.size()-i-1);
    }
}

int getSum()
{
    int sum = 0;
    sort(change, change+27, desc); // 내림차순 정렬
    for(int i = 0 ; change[i] != 0 ; i++) {
        sum += change[i]*(9-i);
    }
    return sum;
}

int main(void)
{
    int n;
    cin >> n; // 단어의 개수
    string s;
    for(int i = 0 ; i < n ; i++) {
        cin >> s;
        init(s);
    }

    cout << getSum() << '\n';
    return 0;
}