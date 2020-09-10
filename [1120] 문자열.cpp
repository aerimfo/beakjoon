// [1120] 문자열
// https://www.acmicpc.net/problem/1120
// 그리디 알고리즘, 브루트 포스

#include <iostream>
using namespace std;

int main(void)
{
    string a, b;
    int gap = 0, minGap = 50;
    cin >> a >> b;

    for(int i = 0 ; i <= b.size() - a.size() ; i++) {
        gap = 0;
        for(int j = 0 ; j < a.size() ; j++) {
            if(a[j] != b[i + j])
                gap++;
        }

        if(minGap > gap)
            minGap = gap;
    }

    cout << minGap << endl;
}