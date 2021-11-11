// [2108] 통계학
// https://www.acmicpc.net/problem/2108

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
vector <int> arr;
map <int, int> frequency;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

void input()
{
    int tmp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
}

void printArithmeticMean()
{
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << round((double)sum / n) << '\n';
}

void printMedianValue()
{
    sort(arr.begin(), arr.end());
    cout << arr[arr.size() / 2] << '\n';
}

void printModeValue()
{
    int maxFrequency = 0, maxNomeIdx = 0;
    vector<pair<int,int> > mapToVector;

    for(int i = 0; i < n; i++) {
        if(frequency.count(arr[i]) != 0) {
            frequency[arr[i]]++;
        }
        else {
            frequency.insert(make_pair(arr[i], 1));
        }
    }

    mapToVector.resize(frequency.size());
    copy(frequency.begin(), frequency.end(), mapToVector.begin());
    sort(mapToVector.begin(), mapToVector.end(), cmp);
    
    for(int i = 0; i < mapToVector.size(); i++) {
        if(mapToVector[i].second > maxFrequency) {
            maxFrequency = mapToVector[i].second;
            maxNomeIdx = i;
        }
    }

    if(maxNomeIdx == mapToVector.size() - 1) {
        cout << mapToVector[maxNomeIdx].first << '\n';
    }
    else {
        cout << mapToVector[maxNomeIdx + 1].first << '\n';
    }
}

void printRange()
{
    cout << arr[n-1] - arr[0] << '\n';
}

int main(void)
{
    input();
    printArithmeticMean();
    printMedianValue();
    printModeValue();
    printRange();
}