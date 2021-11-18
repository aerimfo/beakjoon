// [2503] 숫자 야구
// https://www.acmicpc.net/problem/2503
// 브루트포스 

#include <iostream>
#include <string>
using namespace std;

int n, possibleCnt = 0, arr[101][3], ans;
string ansStr;

void bullsAndCows()
{   
    string questionNum;
    int strikeCnt = 0, ballCnt = 0, possibleCnt = 0;

    for(int i = 123; i <= 987; i++) {
        possibleCnt = 0;
        ansStr = to_string(i);
        
        // 자릿수의 중복 or 한 자리라도 0인 경우 pass
        if(ansStr[0] == ansStr[1] || ansStr[0] == ansStr[2] || ansStr[1] == ansStr[2]) {
            continue;
        }
        else if(ansStr[1] == '0' || ansStr[2] == '0') {
            continue;
        }

        for(int j = 0; j < n; j++) {
            strikeCnt = 0, ballCnt = 0;
            questionNum = to_string(arr[j][0]);
            
            for(int k = 0; k < 3; k++) {
                if(ansStr[k] == questionNum[k]) {
                    strikeCnt++;
                }  
                if(ansStr[k] == questionNum[(k + 1) % 3] || ansStr[k] == questionNum[(k + 2) % 3]) {
                    ballCnt++;
                }
            }

            if(strikeCnt == arr[j][1] && ballCnt == arr[j][2]) {
                possibleCnt++;
            }
        }
        if(possibleCnt == n) {
            ans++;
        }
    }
}

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
}

int main(void)
{
    input();
    bullsAndCows();
    cout << ans << '\n';
}