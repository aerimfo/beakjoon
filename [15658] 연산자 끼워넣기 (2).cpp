// [15658] 연산자 끼워넣기 (2)
// https://www.acmicpc.net/problem/15658

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, a[101], operators[4];
int maxResult = -1000000000, minResult = 1000000000;
vector <int> operatorsArr;

void input()
{
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
}

int compute() 
{ 
    int sum = a[0]; 
    
    for(int i = 0; i < n-1; i++) { 
        switch (operatorsArr[i]) { 
            case 0: 
                sum += a[i + 1]; 
                break; 
            case 1: 
                sum -= a[i + 1]; 
                break; 
            case 2: 
                sum *= a[i + 1]; 
                break; 
            case 3: 
                sum /= a[i + 1]; 
                break; 
            default: 
                break; 
        } 
    } 
   
    return sum; 
}

void getOperatorArray(int cnt) {
	if (cnt == n - 1) {
		int result = compute();
		minResult = min(minResult, result);
		maxResult = max(maxResult, result);
		return;
	}

    for(int i = 0; i < 4; i++) {
        if(operators[i] > 0) {
            operators[i]--;
            operatorsArr.push_back(i);
            getOperatorArray(cnt + 1);
            operatorsArr.pop_back();
            operators[i]++;
        }
    }
}

int main(void)
{
    input();
    getOperatorArray(0);
    cout << maxResult << '\n' << minResult << '\n';
}