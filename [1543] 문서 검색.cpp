// [1543] 문서 검색
// https://www.acmicpc.net/problem/1543
// 브루트포스, 그리디알고리즘
// getline(cin, string) -> 공백 입력

 #include <iostream>
 using namespace std;

int ans;
string document, searchWord;

void input()
{
    getline(cin, document); 
    getline(cin, searchWord);
}

bool check(int startIdx)
{
    for(int i = 0; i < searchWord.size(); i++) {
        if(document[startIdx + i] == searchWord[i]) ;
        else if(document[startIdx + i] != searchWord[i] || startIdx + searchWord.size() >= document.size() + 1) {
            return false;
        }
    }

    ans++;
    return true;
}

void getWordCnt()
{
    for(int i = 0; i < document.size(); i++) {
        if(check(i)) {
            i += searchWord.size() - 1;
        }
    }
}

 int main(void)
 {
    input();
    getWordCnt();
    cout << ans << '\n';
 }