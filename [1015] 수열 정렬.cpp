// [1015] 수열 정렬
// https://www.acmicpc.net/problem/1015

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool num[51];
int n;
vector <int> a, b, p(51, -1);
queue <int> q;
vector <pair<int, int> > remainder;

void input()
{
    int num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }    
}

void getArrayP()
{
    int idx;

    for(int i = n - 1; i >= 0; i--) {
        idx = find(a.begin(), a.end(), b[i]) - a.begin();
        p[idx] = i;
    }

    for(int i = 0; i < n; i++) {
        if(p[i] == -1) {
            remainder.push_back(make_pair(0, i));
        }
    }

    for(int i = 0; i < n; i++) {
        if(find(p.begin(), p.end(), i) == p.end()) {
            q.push(i);
        } 
    }

    for(int i = 0; i < remainder.size(); i++) {
        remainder[i].first = a[remainder[i].second];
    }
    sort(remainder.begin(), remainder.end());

    for(int i = 0; q.size(); i++) {
        p[remainder[i].second] = q.front();
        q.pop();
    }
}

void output()
{
    for(int i = 0; i < n; i++) {
        if(p[i] != -1) {
            cout << p[i] << " ";
        }
        else {
            cout << q.front() << " ";
            q.pop();
        }
    }
}

int main(void)
{
    input(); 
    b.resize(a.size());
    copy(a.begin(), a.end(), b.begin());
    sort(b.begin(), b.end());
    getArrayP();
    output();
}