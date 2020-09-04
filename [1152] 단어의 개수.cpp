// [1152] 단어의 개수
// https://www.acmicpc.net/problem/1152

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int cnt = 0;
    string word;

    // 공백을 포함하여 문자열 입력받기
    getline(cin, word);
    word.insert(0, 1, ' ');

    for(int i = 0 ; i < word.length() ; i++) {
        if(word[i] == ' ') {
            if(('a' <= word[i + 1] && word[i + 1] <= 'z') || ('A' <= word[i + 1] && word[i + 1] <= 'Z')) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}