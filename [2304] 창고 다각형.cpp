// [2304] 창고 다각형
// https://www.acmicpc.net/problem/2304

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, maxHeight = 0, maxHeightIdx;
vector <pair<int, int> > column;

void input()
{
    int p, h;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> p >> h;
        column.push_back(make_pair(p, h));
    }
}

int makeMinWarehouse()
{
    int area = 0, l = -1, r = 1001, height = 0;
    sort(column.begin(), column.end());

    for(int i = 0; i < n; i++) {
        if(column[i].second > maxHeight) {
            maxHeight = column[i].second;
            maxHeightIdx = column[i].first;
        }
    }

    for(int i = 0; column[i].first <= maxHeightIdx; i++) {
        if(column[i].first > l && column[i].second >= height) {
            area += (column[i].first - l) * height;
            l = column[i].first;
            height = column[i].second;
        }
    }

    height = 0;
    for(int i = n-1; column[i].first >= maxHeightIdx; i--) {
        if(column[i].first < r && column[i].second >= height) {
            area += (r - column[i].first) * height;
            r = column[i].first;
            height = column[i].second;
        }
    }

    area += maxHeight;

    return area;
}

int main(void)
{
    input();
    cout << makeMinWarehouse() << '\n';
}