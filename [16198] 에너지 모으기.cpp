// [16198] 에너지 모으기
#include <iostream>
#include <cstring>
using namespace std;

bool visited[11], selected[11];
int n, ans, weight[11], order[11];

int getEnerge()
{
    int left, right, energy = 0;
    memset(selected, false, sizeof(selected));

    for(int i = 1; i <= n-2; i++) {
        left = order[i] - 1, right = order[i] + 1;
        selected[order[i]] = true;
        while(selected[left] == true) left--;
        while(selected[right] == true) right++;
        energy += weight[left] * weight[right];
    }
    return energy;
}

void selectOrder(int idx, int depth)
{
    if(depth == n-1) {
        int energy = getEnerge();
        if(energy > ans) ans = energy;
        return;
    }

    for(int i = 2; i <= n-1; i++) { // 맨 처음과 맨 마지막 구슬은 뽑을 수 없음
        if(visited[i] == false && idx != i) {
            visited[i] = true;
            order[depth] = i;
            selectOrder(i, depth + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
    selectOrder(0, 1);
    cout << ans << '\n';
    return 0;
}