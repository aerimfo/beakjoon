// [1072] 게임
// https://www.acmicpc.net/problem/1072

#include <iostream>
#include <cmath>
using namespace std;

double x, y;

void input()
{
    cin >> x >> y;    
}

int output()
{
    int z = (floor)(100*y/x); // y/x*100 -> 틀림
    if(z >= 99) return -1;
    return (ceil)((x*(z+1) - 100*y) / (99 - z));
}

int main(void)
{
    input();
    cout << output() << '\n';
}