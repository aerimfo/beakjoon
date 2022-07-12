// [1922] 네트워크 연결
// 최소 스패닝 트리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans, parent[1001];
struct Info
{
    int e1;
    int e2;
    int cost;
};
vector<Info> v;

bool cmp(const Info &a, const Info &b)
{
    if(a.cost < b.cost) return true;
    else return false;
}

int find(int a)
{
    if(parent[a] == a) return a;
    else {
        return parent[a] = find(parent[a]);
    }
}

void Union(int a, int b, int cost)
{
    int aRoot = find(a);
    int bRoot = find(b);
    if(aRoot != bRoot) {
        ans += cost;
        parent[aRoot] = bRoot;
    }
}

void solution()
{
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        Union(v[i].e1, v[i].e2, v[i].cost);
    }
    cout << ans << '\n';
}

void init()
{
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Info info = {a, b, c};
        v.push_back(info);
    }
    init();
    solution();
    return 0;
}