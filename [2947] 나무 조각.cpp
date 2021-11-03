// [2947] 나무 조각
// https://www.acmicpc.net/problem/2947

#include <iostream>
using namespace std;

int num[5];

void swap(int i, int j) 
{
    int tmp = num[j];
    num[j] = num[i];
    num[i] = tmp;
}

void printResult()
{
    for(int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
    cout << '\n';
}

void input()
{
    for(int i = 0; i < 5; i++) {
        cin >> num[i];
    }
}

void output()
{
    bool flag;
    while(true) {
        flag = true;
        for(int i = 0; i < 4; i++) {
            if(num[i] > num[i+1]) {
                swap(i, i+1);
                printResult();
                flag = false;
            }
        }
        if(flag) break;
    }
}

int main(void)
{
    input();
    output();
}