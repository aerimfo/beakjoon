// [1138] 한 줄로 서기
// https://www.acmicpc.net/problem/1138

#include <iostream>
using namespace std;

int main(void)
{
    int n; // 사람의 수
    int left[11], line[11] = {0, }; // 왼쪽에 있는 키 큰 사람의 수, 줄을 선 순서
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> left[i];
    }
    for(int i = 1 ; i <= n ; i++) {
        int blank = 0;
        for(int j = 0 ; j < n ; j++) {
            if(line[j] == 0) {
                blank++;
                if(blank == (left[i] + 1)) {
                    line[j] = i;
                    break;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout << line[i] << " ";
    }
}