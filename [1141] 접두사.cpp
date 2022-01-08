// [1141] 접두사
// https://www.acmicpc.net/problem/1141

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;
vector <string> words[51];

void input()
{
    string word;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> word;
        words[word[0]-'a'].push_back(word);
    }
}

bool checkSubset(string s1, string s2)
{
    int minLegnth = s1.size() < s2.size() ? s1.size() : s2.size();
    for(int i = 0; i < minLegnth; i++) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }
    ans--;
    return true;
}

void findMaxSubset()
{
    ans = n;
    for(int i = 0; i < 26; i++) {
        sort(words[i].begin(), words[i].end());
        if(words[i].size() > 0) {
            for(int j = 0; j < words[i].size() - 1; j++) {
                if(checkSubset(words[i][j], words[i][j+1]) == false) {
                    continue;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    input();
    findMaxSubset();
}