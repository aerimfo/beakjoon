// [5557] 1학년
// dp
// dp[i][j] = i번째 수까지의 합이 j인 경우의 수
#include <iostream>
using namespace std;

int n, arr[100];
long long dp[100][21];

void solution(){
  dp[0][arr[0]] = 1;

  for(int i = 1; i < n - 1; i++) {
    for(int j = 0; j < 21; j++) {
      if(dp[i - 1][j] > 0) {
        if(j + arr[i] <= 20) {
            dp[i][j + arr[i]] += dp[i - 1][j];
        }
        if(j - arr[i] >= 0) {
            dp[i][j - arr[i]] += dp[i - 1][j];  
        }
      }
    }
  }
  
  cout << dp[n - 2][arr[n - 1]] << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  solution();
}