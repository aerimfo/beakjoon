// [1316] 그룹 단어 체커
// https://www.acmicpc.net/problem/1316

#include <iostream>
#include <cstring>
using namespace std;

int n, lastIdx[27];
string words[101];

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
}

bool checkGroupWords(string word)
{
    memset(lastIdx, -1, sizeof(lastIdx));
    for(int i = 0; i < word.size(); i++) {
        if(lastIdx[word[i] - 'a'] == -1 || i - lastIdx[word[i] - 'a'] == 1) {
            lastIdx[word[i] - 'a'] = i;  
        }  
        else {
            return false;
        }
    }
    
    return true;
}

int output()
{
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        if(checkGroupWords(words[i])) {
            ans++;
        }
    }

    return ans;
}

int main(void)
{
    input();
    cout << output() << '\n';
}