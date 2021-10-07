// [2630] 색종이 만들기
// https://www.acmicpc.net/problem/2630
// [1780] 종이의 개수와 매우 유사!
// 분할 정복

#include <iostream>
using namespace std;

int n, paper[129][129], cnt[2];

void input()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> paper[i][j];
        }
    }
}

bool check(int x, int y, int n)
{
    for (int i = x ; i < x + n ; i++) {
        for (int j = y ; j < y + n ; j++) {
            if (paper[i][j] != paper[x][y]) {
                return false;
            }
        }
    }
	return true;
}

void cutPaper(int x, int y, int size)
{
    if (check(x, y, size) == true) {
		cnt[paper[x][y]] += 1;
		return;
	}

    else {
		cutPaper(x, y, size/2);
        cutPaper(x, y + size/2, size/2);
        cutPaper(x + size/2, y, size/2);
        cutPaper(x + size/2, y + size/2, size/2);
	}
}

void output()
{
    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    check(0, 0, n);
    cutPaper(0, 0, n);
    output();

    return 0;
}