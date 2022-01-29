// [3568] iSharp
// https://www.acmicpc.net/problem/3568

#include <iostream>
#include <string>
using namespace std;

string commonType, str;

void input()
{
    cin >> commonType;
    cin.ignore(); // 맨 앞의 문자 하나 지움(\n);
    getline(cin, str);
}

void output(string extraType, string val)
{
    cout << commonType;
    for(int j = extraType.size() - 1; j >= 0; j--) {
        if(extraType[j] == '[') {
            cout << ']';
        } else if(extraType[j] == ']') {
            cout << '[';
        } else {
            cout << extraType[j];
        }
    }
    cout << ' ' << val << ";\n";
}

void seperateDeclarations()
{
    string extraType = "", val = "";

    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        if(c == ' ') continue;
        else if(c == ',' || c == ';') {
            output(extraType, val);
            extraType = ""; val = "";
            continue;
        }
        else if(isalpha(c)) {
            val += c;
        } else {
            extraType += c;
        }
    }
}

int main() {
    input();
    seperateDeclarations();

    return 0;
}