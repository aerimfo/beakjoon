// [10828] 스택
// 자료 구조, 스택
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, num;
    string instruction;
    stack<int> st;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> instruction;
        if(instruction == "push") {
            cin >> num;
            st.push(num);
        }
        else if(instruction == "pop") {
            if(!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else cout << "-1\n";
        }
        else if(instruction == "size") {
            cout << st.size() << '\n';
        }
        else if(instruction == "empty") {
            if(st.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else {
            if(!st.empty()) cout << st.top() << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}