#include<bits/stdc++.h>
using namespace std;
const int n_inf=2e6+100;
const int q_inf=2e6+100;
int n,m,l,r,ql,qr,len,now;
int a[n_inf],cnt[n_inf],id[n_inf],ans[q_inf];
struct query{
    int l,r,id;
}q[q_inf];
bool cmp(query &a,query &b){
    return (id[a.l]^id[b.l]) ? id[a.l]<id[b.l] : ((id[a.l]&1) ? a.r<b.r : a.r>b.r);
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++) id[i]=(i-1)/len+1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    l=1,r=0;
    for(int i=1;i<=m;i++){
        ql=q[i].l,qr=q[i].r;
        while(l<ql) now-=!--cnt[a[l++]];
        while(l>ql) now+=!cnt[a[--l]]++;
        while(r<qr) now+=!cnt[a[++r]]++;
        while(r>qr) now-=!--cnt[a[r--]];
        ans[q[i].id]=now;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
    return 0;
}