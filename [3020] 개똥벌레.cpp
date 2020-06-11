// [3020] 개똥벌레
// https://www.acmicpc.net/problem/3020
// 이분 탐색, 정렬

#include <vector>
#include <algorithm> // lower_bound()
#include <cstdio>
using namespace std;

int main(void)
{
    /* 
    cnt = 각 구간마다 개똥벌레가 파괴해야 하는 석순 & 종유석 개수
    section = 개똥벌레가 지나갈 구간
    min = 개똥벌레가 파괴하는 석순 & 종유석 개수의 최솟값
    ans = min값을 가지는 구간의 개수
    */
    int n, h, tmp1, tmp2, cnt = 0, min, section, ans = 1;
    vector <int> stalagmite, stalacitite; // 석순, 종유석
    scanf("%d %d", &n, &h);
    min = n;
    for(int i = 0 ; i < n/2 ; i++) {
        scanf("%d %d ", &tmp1, &tmp2);
        stalagmite.push_back(tmp1);
        stalacitite.push_back(h - tmp2); // 바닥부터 종유석까지의 거리를 저장 
    }

    sort(stalagmite.begin(), stalagmite.end());
    sort(stalacitite.begin(), stalacitite.end());

    for(int section = 1 ; section <= h ; section++) {
        // 석순과 구간이 만나는 최소 인덱스 탐색
        int it = lower_bound(stalagmite.begin(), stalagmite.end(), section) - stalagmite.begin();
        // 인덱스 it부터 석순의 끝 인덱스까지는 구간과 모두 만남 
        cnt = n/2 - it;

        // 종유석과 구간이 만나는 최소 인덱스 탐색
        it = lower_bound(stalacitite.begin(), stalacitite.end(), section) - stalacitite.begin();
        /* 종유석 벡터 : (바닥 ~ 종유석) 거리
           -> 구간과 stalacitite 벡터가 만난다면 종유석과 구간은 만나지 않는다는 뜻
           -> 처음부터 인덱스 it 직전까지만 종유석과 구간이 만남 
        */
        cnt += it;

        if(cnt < min) {
            min = cnt;
            ans = 1;
        }   
        else if(cnt == min) {
            ans++;
        }
    }
    printf("%d %d\n", min, ans);
}