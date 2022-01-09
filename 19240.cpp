// [19240] 장난감 동맹군
// https://www.acmicpc.net/problem/19240

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// group[0]: 배정 안함, group[1]: 첫번째 그룹, group[2]: 두번째 그룹
int toy[17], group[17];
vector <vector<int> > bad(17); // 사이가 좋지 않은 장난감 관계

void split(int n, int m)
{   
    int tmp = 1;
    for(int i = 1 ; i <= n ; i++) {
        if(bad[i].size() != 0) { // 사이가 안좋은 장난감이 있다면
            if(group[i] == 0) {
                group[i] = tmp;
            }
            //printf("i: group[%d] = %d\n", i, group[i]);
            for(int j = 0 ; j < bad[i].size() ; j++) {
                if(group[bad[i][j]] != 0) {
                    if((3 - group[i]) != group[bad[i][j]]) {
                        cout << "NO" << '\n';
                        return;
                    }
                }
                else {
                    group[bad[i][j]] = 3 - group[i];
                    //printf("j: group[%d] = %d\n", bad[i][j], group[bad[i][j]]);
                }
            }
        }
    }
    cout << "YES" << '\n';
    return;
}

int main(void)
{
    int t, n, m, tmp1, tmp2;
    cin >> t;
    while(t--) {
        for (int i = 0; i < bad.size() ; i++) {
            bad[i].clear();
        }
        bad.clear();
        for(int i = 0 ; i < 17 ; i++) {
            group[i] = 0;
        }
        //memset(group, 0, sizeof(group));
        cin >> n >> m;
        for(int i = 0 ; i < m ; i++) {
            cin >> tmp1 >> tmp2;
            bad[tmp1].push_back(tmp2);
        }
        // for(int i = 0 ; i < 17 ; i++) {
        //     for(int j = 0 ; j < bad[i].size() ; j++) {
        //         printf("bad[%d][%d] = %d\n", i,j, bad[i][j]);
        //     }
        // }
        split(n, m);
    }
}