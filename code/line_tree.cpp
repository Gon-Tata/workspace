#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
#define int long long
#define lson (id<<1)
#define rson (id<<1|1)
struct jtr{
    int l,r;
    int sum;
    int lazy_sign;
}tre[4*inf];
int m,n,a[inf],j,x,y,k;
void build (int id,int l,int r){
    tre[id].l=l;
    tre[id].r=r;
    if(l==r){
        tre[id].sum=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    tre[id].sum=tre[lson].sum+tre[rson].sum;
    return ;
}
void pushdown(int id){
    if(tre[id].lazy_sign&&tre[id].l!=tre[id].r){
        tre[lson].lazy_sign+=tre[id].lazy_sign;
        tre[rson].lazy_sign+=tre[id].lazy_sign;
        tre[lson].sum+=tre[id].lazy_sign*(tre[lson].r-tre[lson].l+1);
        tre[rson].sum+=tre[id].lazy_sign*(tre[rson].r-tre[rson].l+1);
        tre[id].lazy_sign=0;
    }
    return ;
}
void add(int id,int l,int r,int val){
    if(tre[id].l>=l&&tre[id].r<=r){
        tre[id].lazy_sign+=val;
        tre[id].sum+=val*(tre[id].r-tre[id].l+1);
        return ;
    }
    pushdown(id);
    int mid=(tre[id].l+tre[id].r)>>1;
    if(l<=mid) add(lson,l,r,val);
    if(r>mid) add(rson,l,r,val);
    tre[id].sum=tre[lson].sum+tre[rson].sum;
    return ;
}
int query(int id,int l,int r){
    if(tre[id].l>=l&&tre[id].r<=r) return tre[id].sum;
    pushdown(id);
    int mid=(tre[id].l+tre[id].r)>>1;
    int v=0;
    if(l<=mid) v=query(lson,l,r);
    if(r>mid) v+=query(rson,l,r);
    return v;
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%lld",&j);
        if(j==1){
            scanf("%lld%lld%lld",&x,&y,&k);
            add(1,x,y,k);
        }
        else{
            scanf("%lld%lld",&x,&y);
            k=query(1,x,y);
            printf("%lld\n",k);
        }
    }
    return 0;
}