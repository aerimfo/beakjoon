// [4796] 캠핑
// https://www.acmicpc.net/problem/4796

#include <cstdio>

void days(int i, int l, int p, int v)
{
    int ans = 0;
    if(v%p <= l) { 
        ans = (v/p)*l + (v%p);
    }
    else {
        ans = (v/p)*l + l;
    }
    printf("Case %d: %d\n", i, ans);
}

int main(void)
{
    int i = 1, l, p, v; 

    while(true) {
        scanf("%d %d %d", &l, &p, &v);
        if(l+p+v == 0) break;
        else {
            days(i, l, p, v);
            i++;
        }
    }
}