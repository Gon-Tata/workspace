#include <bits/stdc++.h>
using namespace std;
const int inf = 4e5+100;
const int maxn = 1e9+10;
int n, x, y, cnt ,tot, fa[inf], root[inf];
int opt;
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
struct treeeeeeeeee
{
    int lson, rson, size, tag;
    double val;
} tr[inf*20];
inline void erase(int x){
    tr[x].size=0;
    tr[x].val=0;
    tr[x].tag=1;
}
inline void push_down(int x){
    if(!tr[x].tag) return ;
    erase(tr[x].lson);
    erase(tr[x].rson);
    tr[x].tag=0;
}
inline void push_up(int a)
{
    tr[a].size = tr[tr[a].lson].size + tr[tr[a].rson].size;
    tr[a].val = tr[tr[a].lson].val + tr[tr[a].rson].val;
}
int merge(int a,int b,int l,int r){
    if (!a || !b)
        return a + b;
    if (l == r)
    {
        tr[a].size += tr[b].size;
        tr[a].val += tr[b].val;
        return a;
    }
    int mid = (l + r) >> 1;
    push_down(a);
    push_down(b);
    tr[a].lson = merge(tr[a].lson, tr[b].lson, l, mid);
    tr[a].rson = merge(tr[a].rson, tr[b].rson, mid + 1, r);
    push_up(a);
    return a;
}
void ins(int &rt,int l, int r, int pos,int k){
    // int pos = ++cnt;
    // tr[pos].val = val;
    if(!rt) rt=++tot;
    if(l==r){
        tr[rt].size+=k;
        tr[rt].val+=1.0*k*log(pos);
        return ;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if(pos<=mid) ins(tr[rt].lson, l, mid, pos,k);
    else ins(tr[rt].rson, mid + 1, r, pos,k);
    push_up(rt);
}
void update(int rt,int l,int r,int ql,int qr,int &oto){
    if(l>=ql&&r<=qr){
        oto+=tr[rt].size;
        erase(rt);
        return;
    }
    int mid=(l+r)>>1;
    push_down(rt);
    if(ql<=mid) update(tr[rt].lson,l,mid,ql,qr,oto);
    if(qr>mid) update(tr[rt].rson,mid+1,r,ql,qr,oto);
    push_up(rt);
}
int query_num(int rt, int l, int r, int q)
{
    push_down(rt);
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (tr[tr[rt].lson].size >= q)
        return query_num(tr[rt].lson, l, mid, q);
    else
        return query_num(tr[rt].rson, mid+1,r,q - tr[tr[rt].lson].size);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&opt);
        if (opt == 1){
            scanf("%d",&x);
            cnt++;
            fa[cnt]=cnt;
            // root[cnt]=cnt;
            ins(root[cnt],1,maxn,x,1);
            continue;
        }
        if (opt == 2){
            scanf("%d%d",&x,&y);
            int fx=find(x),fy=find(y);
            if(fx!=fy){
                fa[fy]=fx;
                root[fx]=merge(root[fx],root[fy],1,maxn);
            }
            continue;
        }
        if (opt == 3){
            int tmp=0;
            scanf("%d%d",&x,&y);
            x=find(x);
            update(root[x],1,maxn,1,y-1,tmp);
            ins(root[x],1,maxn,y,tmp);
            continue;
        }
        if (opt == 4){
            int tmp=0;
            scanf("%d%d",&x,&y);
            x=find(x);
            update(root[x],1,maxn,y+1,maxn,tmp);
            ins(root[x],1,maxn,y,tmp);
            continue;
        }
        if (opt == 5){
            scanf("%d%d",&x,&y);
            x=find(x);
            int ans=query_num(root[x],1,maxn,y);
            cout<<ans<<'\n';
            continue;
        }
        if (opt == 6){
            scanf("%d%d",&x,&y);
            x=find(x);
            y=find(y);
            cout<<(tr[root[x]].val>tr[root[y]].val)<<'\n';
            continue;
        }
        if (opt == 7){
            scanf("%d",&x);
            x=find(x);
            cout<<tr[root[x]].size<<'\n';
        }
    }
}
/*

Keep dreaming
Remain loving


*/