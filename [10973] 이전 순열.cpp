// [10973] 이전 순열
// https://www.acmicpc.net/problem/10973
// 수학, 조합론

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> num;

void find(int n)
{
    int cnt = 1;
    do
    {   
        if(cnt == 2) {
            for(int i = 0 ; i < n ; i++) {
                cout << num[i] << " ";
            }
            return;
        }
        cnt++;
    } while (prev_permutation(num.begin(), num.end()));

    cout << "-1" << '\n';
    return;
    
}

int main(void)
{
    int n, tmp;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }

    find(n);
    return 0;
}