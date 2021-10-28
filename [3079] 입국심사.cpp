// [3079] 입국심사
// https://www.acmicpc.net/problem/3079
// 이분 탐색

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, maxNum = 0;
vector <long long> immigrateCheck;

void input()
{
    int tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        immigrateCheck.push_back(tmp);
        maxNum = max(maxNum, immigrateCheck[i]);
    }
}

void binarySearch()
{
    long long left = 0, right = maxNum * m, mid, sum;
    long long ans = right;

    while(left <= right){
        sum = 0;
        mid = (left + right) / 2;
        for(int i = 0; i < n; i++){
            sum += (mid / immigrateCheck[i]);
        }

        if(sum >= m){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main(){
    input();
    binarySearch();
}
