// [1148] 단어 만들기
// https://www.acmicpc.net/problem/1148

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int puzzleWord[27];
vector <string> words;
vector <pair<int, char> > usedAlphabet;

void inputWords()
{
    string word;
    for(int i = 0; ; i++) {
        cin >> word;
        if(word != "-") {
            words.push_back(word);
        }
        else {
            break;
        }
    }
}

void initialization()
{
    usedAlphabet.clear();
    for(int i = 0; i < 26; i++) {
        usedAlphabet.push_back(make_pair(0, i + 'A'));
    }
}

void printAns()
{
    int min, max;
    for(int i = 0; i < usedAlphabet.size(); i++) {
        if(puzzleWord[usedAlphabet[i].second - 'A'] > 0) {
            min = usedAlphabet[i].first;
            break;
        }
    }

    for(int i = 0; i < usedAlphabet.size(); i++) {
        if(usedAlphabet[i].first == min && puzzleWord[usedAlphabet[i].second - 'A'] > 0) {
            cout << usedAlphabet[i].second;
        }
    }
    cout << " " << min << " ";

    for(int i = 0; i < usedAlphabet.size(); i++) {
        max = usedAlphabet[25].first;
        if(usedAlphabet[i].first == max && puzzleWord[usedAlphabet[i].second - 'A'] > 0) {
            cout << usedAlphabet[i].second;
        }
    }
    cout << " " << max << '\n';
}

void getAns()
{
    initialization();

    for(int i = 0; i < words.size(); i++) {
        bool flag = true;
        int alphabet[27] = {0,};
        for(int j = 0; j < words[i].size(); j++) {
            alphabet[words[i][j] - 'A']++;
        }

        for(int j = 0; j < 26; j++) {
            if(alphabet[j] <= puzzleWord[j]) ;
            else {
                flag = false;
                break;
            }
        }

        if(flag == true) {
            for(int j = 0; j < 26; j++) {
                if(alphabet[j] > 0) {
                    usedAlphabet[j].first += 1;
                }
            }
        }
    }

    sort(usedAlphabet.begin(), usedAlphabet.end());
    printAns();
}

void inputPuzzles()
{
    string puzzle;
    while(true) {
        memset(puzzleWord, 0, sizeof(puzzleWord));
        cin >> puzzle;
        if(puzzle != "#") {
            for(int i = 0; i < 9; i++) {
                puzzleWord[puzzle[i] - 'A'] += 1;
            }
            getAns();
        }
        else {
            break;
        }
    }
}

int main(void)
{
    inputWords();
    inputPuzzles();
}