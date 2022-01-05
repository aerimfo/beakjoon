// [1064] 평행사변형
// https://www.acmicpc.net/problem/1064

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long double xa, ya, xb, yb, xc, yc;

void input()
{
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
}

void findAllParallelogram()
{
    vector <long double> perimeter;
    long double ac = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    long double bc = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
    long double ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    
    perimeter.push_back(2*ac + 2*bc);
    perimeter.push_back(2*ab + 2*bc);
    perimeter.push_back(2*ab + 2*ac);

    sort(perimeter.begin(), perimeter.end());

    cout.precision(10);
    cout << perimeter[2] - perimeter[0] << '\n';
}

void checkpParallelogram()
{
    if((xb - xa != 0) && (xc - xa != 0)) {
        if(((yb - ya) / (xb - xa) == (yc - ya) / (xc - xa))) {
            cout << -1 << '\n';
        }
        else {
            findAllParallelogram();
        }
    }
    else if(xa == xb && xb == xc) {
        cout << -1 << '\n';
    }
    else if(ya == yb && yb == yc) {
        cout << -1 << '\n';
    }
    else {
        findAllParallelogram();
    }
}

int main(void)
{
    input();
    checkpParallelogram();
}