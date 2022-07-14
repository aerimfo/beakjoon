// [1915] 가장 큰 정사각형
// dp
// dp[i][j] = (i, j)칸을 포함하는 가장 큰 정사각형의 한 변의 길이
#include <iostream>
#include <cmath>
using namespace std;

int n, m, dp[1001][1001];
string arr[1001];

int findMaxSqure()
{
    int maxLength = 0;
    for(int i = 0; i < n; i++) {
        dp[i][0] = (arr[i][0] - '0');
        if(dp[i][0] == 1) maxLength = 1;
    }

    for(int i = 0; i < m; i++) {
        dp[0][i] = (arr[0][i] - '0');
        if(dp[0][i] == 1) maxLength = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) { 
            if(arr[i][j] == '0') dp[i][j] = 0;
            else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
           
            if(dp[i][j] > maxLength) maxLength = dp[i][j];
        }
    }
    return maxLength * maxLength;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findMaxSqure() << '\n';

    return 0;
}