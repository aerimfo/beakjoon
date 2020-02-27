// [1085] 직사각형에서 탈출
// https://www.acmicpc.net/problem/1085

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> distance; //distance(4) 라고 하면 안됨(0, 0, 0, 0, x, y, w-x, h-y 꼴이 되기 때문) 
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	distance.push_back(x);
	distance.push_back(y);
	distance.push_back(w - x);
	distance.push_back(h - y);
	sort(distance.begin(), distance.end());
	cout << distance[0];
}