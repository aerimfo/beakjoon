// [2517] 달리기
// 세그먼트 트리, 좌표 압축
// 실력 1~i인 학생의 수 = 실력이 (i+1)인 학생의 등수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, tmpN, tree[1024*1024*2];

struct SkillInfo {
    int skill;
    int idx;
};

bool skillCmp(SkillInfo a, SkillInfo b)
{
    return a.skill < b.skill;
}

bool idxCmp(SkillInfo a, SkillInfo b)
{
    return a.idx < b.idx;
}

void update(int a)
{
    while(a > 0) {
        a = a >> 1;
        tree[a] = tree[a * 2] + tree[a * 2 + 1];
    }
}

int getSum(int a, int b)
{
    int sum = 0;
    while(a <= b) {
        // a가 right child라면(짝수라면)
        if((a & 1) == 1) sum += tree[a];
        // b가 left child라면(홀수라면)
        if((b & 1) == 0) sum += tree[b];
        a = (a + 1) >> 1; // 오른쪽 친구의 부모로 올라감
        b = (b - 1) >> 1; // 자기 부모로 올라감
    }
    return sum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num;
    vector<SkillInfo> v;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        SkillInfo info = {num, i};
        v.push_back(info);
    }
    sort(v.begin(), v.end(), skillCmp);
    for(int i = 0; i < n; i++) { // 좌표 압축
        v[i].skill = i + 1;
    }
    sort(v.begin(), v.end(), idxCmp);
    for(tmpN = 1; tmpN < n; tmpN *= 2); // tmpN = leafnode 개수
    for(int i = 0; i < tmpN * 2; i++) { // 트리 내 값 초기화
        tree[i] = 0;
    }
    for(int i = 0; i < n; i++) { // leaf 채우기
        tree[tmpN + v[i].skill - 1] = 1;
        update(tmpN + v[i].skill - 1);
        cout << getSum(tmpN + v[i].skill - 1, tmpN + n - 1) << '\n';
    }
    return 0;
}