#include <bits/stdc++.h>
using namespace std;
#define lson id << 1
#define rson id << 1 | 1
const int maxn = 10005;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct star
{
    int x, y, z;
    int c;
    void input()
    {
        x = read();
        y = read();
        c = read();
    }
    friend bool operator<(star fir, star sec)
    {
        return fir.x < sec.x || (fir.x == sec.x && fir.c < sec.c);
    }
} a[maxn << 1];
int b[maxn << 1];
int n, w, h;
struct segment_tree
{
    int l, r;
    int val;
    int lazy;
} tr[maxn << 4];
void build(int id, int l, int r)
{
    tr[id].l = l;
    tr[id].r = r;
    tr[id].val = tr[id].lazy = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void push_down(int id)
{
    tr[lson].lazy += tr[id].lazy;
    tr[lson].val += tr[id].lazy;
    tr[rson].lazy += tr[id].lazy;
    tr[rson].val += tr[id].lazy;
    tr[id].lazy = 0;
}
void push_up(int id)
{
    tr[id].val = max(tr[lson].val, tr[rson].val);
}
void change(int id, int l, int r, int c)
{
    if (l <= tr[id].l && tr[id].r <= r)
    {
        tr[id].val += c;
        tr[id].lazy += c;
        return;
    }
    if (tr[id].lazy)
        push_down(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (l <= mid)
        change(lson, l, r, c);
    if (r > mid)
        change(rson, l, r, c);
    push_up(id);
}
int main()
{
    freopen("o.in", "r", stdin);
    while (scanf("%d%d%d", &n, &w, &h) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            int id = i << 1;
            a[id - 1].input();
            a[id].x = a[id - 1].x + w;
            b[id - 1] = a[id].y = a[id - 1].y;
            b[id] = a[id].z = a[id - 1].z = a[id - 1].y + h - 1;
            a[id].c = -a[id - 1].c;
        }
        n <<= 1;
        sort(b + 1, b + 1 + n);
        int m = unique(b + 1, b + 1 + n) - (b + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i].y = lower_bound(b + 1, b + 1 + m, a[i].y) - b;
            a[i].z = lower_bound(b + 1, b + 1 + m, a[i].z) - b;
        }
        sort(a + 1, a + 1 + n);
        build(1, 1, m);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            change(1, a[i].y, a[i].z, a[i].c);
            ans = max(ans, tr[1].val);
        }
        printf("%d\n", ans);
    }
    return 0;
}