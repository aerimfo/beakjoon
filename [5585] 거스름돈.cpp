// [5585] 거스름돈
// https://www.acmicpc.net/problem/5585

#include <iostream>
using namespace std;

int main(void)
{
    int money, change; // 지불해야 할 돈, 받아야 할 거스름돈
    int cnt = 0; // 잔돈 개수
    cin >> money;
    change = 1000 - money;
    while(change) {
        if(change / 500 > 0) { // 500엔
            cnt += (change / 500);
            change %= 500;
        }
        else if(change / 100 > 0) { //100엔
            cnt += (change / 100);
            change %= 100;
        }
        else if(change / 50 > 0) { // 50엔
            cnt += (change / 50);
            change %= 50;
        }
        else if(change / 10 > 0) { // 10엔
            cnt += (change / 10);
            change %= 10;
        }
        else if(change / 5 > 0) { // 5엔
            cnt += (change / 5);
            change %= 5;
        }
        else // 1엔
        {
            cnt += change;
            break;
        }
        
    }
    cout << cnt << endl;
}