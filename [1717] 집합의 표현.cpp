// [1717] 집합의 표현
// 유니온 파인드
#include <iostream>
using namespace std;

int parent[1000001];

int find(int a)
{
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    int aRoot = find(a);
    int bRoot = find(b);
    parent[aRoot] = bRoot;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, oper, a, b;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> oper >> a >> b;
        if(oper == 0) {
            Union(a, b);
        }
        else {
            int aRoot = find(a);
            int bRoot = find(b);
            if(aRoot == bRoot) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}