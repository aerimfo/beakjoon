// [2961] 도영이가 만든 맛있는 음식
// https://www.acmicpc.net/problem/2961

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, taste[11][2], minGap = 1000000000;
vector <int> arr; 

void input()
{
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> taste[i][0] >> taste[i][1];
    }
}

void getDiffrence()
{
    int s = 1, b = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            s *= taste[i][0];
            b += taste[i][1];
        }
    }

    if(abs(s - b) < minGap) { 
        minGap = abs(s - b); 
    }
}

void makeArray()
{
    int max = 0, min = 1000000000;

    for(int i = 1; i <= n; i++) {
        arr.clear();
        for(int j = 0; j < n-i; j++) {
            arr.push_back(0);
        }
        for(int k = 0; k < i; k++) {
            arr.push_back(1);
        }

        do { 
            getDiffrence();
        } while(next_permutation(arr.begin(),arr.end()));
    }
}

int main(void)
{
    input();
    makeArray();
    cout << minGap << '\n';
}