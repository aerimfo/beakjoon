// [14888] 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888
// 브루트 포스

#include <cstdio>
#include <vector>
#include <algorithm> // next_permutation()
using namespace std;

vector <int> operators;
int a[12];
int compute(int n);

int main(void)
{
    int n, cnt, max = -1000000000, min = 1000000000;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }

    // index 0 = '+', 1 = '-', 2 = '*', 3 = '/'
    for(int i = 0 ; i < 4 ; i++) {
        scanf("%d", &cnt);
        for(int j = 0 ; j < cnt ; j++) {
            operators.push_back(i);
        }
    }

    do{
        if(compute(n) > max) {
            max = compute(n);
        }
        if(compute(n) < min) {
            min = compute(n);
        }
	}while(next_permutation(operators.begin(),operators.end()));

    printf("%d\n%d\n", max, min);
}

int compute(int n)
{
    int sum = 0;
    operators.insert(operators.begin(), 0); // 맨 처음 숫자는 무조건 더해줘야 함
    for(int i = 0 ; i < n ; i++) {
        switch (operators[i])
        {
        case 0:
            sum += a[i];
            break;
        case 1:
            sum -= a[i];
            break;
        case 2:
            sum *= a[i];
            break;
        case 3:
            sum /= a[i];
            break;
        default:
            break;
        }
    }
    operators.erase(operators.begin());
    return sum;
}