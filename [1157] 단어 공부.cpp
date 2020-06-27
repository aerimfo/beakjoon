// [1157] 단어 공부
// https://www.acmicpc.net/problem/1157

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string word;
    char ans;
    int alpha[27] = {0,}, cnt = 0, max = -1, maxi = -1;
    cin >> word;
    for(int i = 0 ; i < word.size() ; i++) {
        // 대문자인 경우
        if(65 <= word[i] && word[i] <= 90) {
            alpha[word[i] - 'A']++;
        }
        // 소문자인 경우
        else {
            alpha[word[i] - 'a']++;
        }
    }

    for(int i = 0 ; i < 27 ; i++) {
        if(alpha[i] > max) {
            cnt = 0;
            max = alpha[i];
            maxi = i;
        }
        else if(alpha[i] == max) {
            cnt++;
        }
    }

    // 가장 많이 사용된 알파벳이 여러개인 경우
    if(cnt > 0) {
        cout << '?' << '\n';
    }
    else {
        // 인덱스를 문자로 변환
        ans = maxi + 'A';

        cout << ans << '\n';
    }
}