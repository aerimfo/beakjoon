// [2872] 우리집엔 도서관이 있어
// https://www.acmicpc.net/problem/2872

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, ans = 0; // 책의 개수, 움직여야 할 책의 개수
    int tmp, maxi, max = 0;
    vector <int> books; // 책 번호
    cin >> n;
    books.insert(books.begin(), 0); // 시작 인덱스를 1로 해주기 위해 0번째 자리에 아무값 삽입
    ans = n - 1; // 가장 큰 번호의 책은 항상 뽑을 필요가 없음
    for(int i = 1 ; i <= n ; i++) {
        cin >> tmp;
        books.push_back(tmp);
        if(books[i] > max) {
            max = books[i];
            maxi = i; // 가장 큰 번호를 갖고 있는 책의 위치
        }
    }
    for(int i = maxi - 1 ; i >= 1 ; i--) {
        if(books[maxi] == books[i] + 1) {
            maxi = i;
            ans--;
        }
    }
    cout << ans << endl;
}