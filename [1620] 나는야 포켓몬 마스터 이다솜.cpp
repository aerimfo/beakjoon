// [1620] 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620
// binary search
// cin, cout, c 표준 입출력(printf, scanf)을 혼용할 경우 틀림
// 즉, 멀티 쓰레드 환경이 아닌 싱글 쓰레드 환경이어야 함
// 알고리즘 문제풀이시에만 사용하고 실무에서는 사용 X

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n, m;
    string key;
    vector <string> poketmon;
    pair<string, int> dictionary[100001];
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) {
        cin >> key;
        poketmon.push_back(key);
        dictionary[i].first = poketmon[i]; dictionary[i].second = i;
    }

    // 사전순으로 정렬
    sort(dictionary, dictionary + n);

    for(int i = 0 ; i < m ; i++) {
        cin >> key;
        
        // 입력이 '문자'라면
        if(65 <= (int)key[0] && (int)key[0] <= 90) {
            int mid, left = 0, right = n - 1;
            while(left <= right) {
                mid = (left + right) / 2;
                if(dictionary[mid].first < key) {
                    left = mid + 1;
                }
                else if(dictionary[mid].first > key) {
                    right = mid - 1;
                }
                else {
                    // endl 대신  /n을 사용할 것!(endl은 출력 버퍼를 비우기 때문에 느림)
                    cout << dictionary[mid].second + 1 << '\n';
                    break;
                }
            }
        }
        // 입력이 '숫자'라면
        else {
            cout << poketmon[atoi(key.c_str()) - 1] << '\n';
        }
    }
}