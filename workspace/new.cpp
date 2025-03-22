#include <bits/stdc++.h>
using namespace std;
#define lson id << 1
#define rson id << 1 | 1
const int N = 1e4 + 10;
const int inf = 5e4;
int n, w, h, x, y, c, ans;
int cnt[2];
struct lineeeeeeeee
{
    int l;
    int r;
    int h;
    int val;
} lin[2][inf];
struct treeeeeeeeee
{
    int l, r, sum;
    int len;
} tr[2][inf << 2];
bool cmp(lineeeeeeeee &a, lineeeeeeeee &b)
{
    return a.h != b.h ? a.h < b.h : a.val > b.val;
}
void build(int id, int l, int r, int k)
{
    tr[k][id].l = l;
    tr[k][id].r = r;
    tr[k][id].len = tr[k][id].sum = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lson, l, mid, k);
    build(rson, mid + 1, r, k);
}
void push_up(int id, int k)
{
    if (tr[k][id].sum)
        tr[k][id].len = tr[k][id].r - tr[k][id].l + 1;
    else if (tr[k][id].l == tr[k][id].r)
        tr[k][id].len = 0;
    else
        tr[k][id].len = tr[k][lson].len + tr[k][rson].len;
}
void update(int id, int l, int r, int val, int k)
{
    int kl = tr[k][id].l, kr = tr[k][id].r;
    if (kl > r || kr < l)
        return;
    if (l <= kl && r >= kr)
    {
        tr[k][id].sum += val;
        push_up(id, k);
        return;
    }
    update(lson, l, r, val, k);
    update(rson, l, r, val, k);
    push_up(id, k);
}
int main()
{
    freopen("o.in","r",stdin);
    // freopen("a.out","w",stdout);
    while(cin >> n >> w >> h){
        for(int i = 1; i <= n;i++){
            scanf("%d%d%d", &x, &y, &c);
            
        }
    }
    return 0;
}
/*

Keep dreaming
Remain loving

*/