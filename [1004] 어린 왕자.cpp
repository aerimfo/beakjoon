// [1004] 어린 왕자
// https://www.acmicpc.net/problem/1004

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool s, e;
int planet[51][3];
int x_1, y_1, x_2, y_2, n;

int getMinEntry()
{
    int ans = 0;
 
    for(int i = 0; i < n; i++) {
        s = false; e = false;
        if(planet[i][2]*planet[i][2] > (x_1 - planet[i][0])*(x_1 - planet[i][0]) + (y_1 - planet[i][1])*(y_1 - planet[i][1])) {
            s = true;
        }
        if(planet[i][2]*planet[i][2] > (x_2 - planet[i][0])*(x_2 - planet[i][0]) + (y_2 - planet[i][1])*(y_2 - planet[i][1])) {
            e = true;
        }
        if((s && !e) || (!s && e)) {
            ans++;
        }      
    }

    return ans;
}

void input()
{
    int t;
    cin >> t;
    while(t--) {
        memset(planet, 0, sizeof(planet));
        
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> planet[i][0] >> planet[i][1] >> planet[i][2];
        }

        cout << getMinEntry() << '\n';
    }
}

int main(void)
{
    input();
}