#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e5+100;
int n,m,l,r,ic=1,ql,qr,len,tot,now,tmp,bnum;
int a[inf],id[inf],ls[inf],rs[inf],inp[inf],col[inf],ans[inf],sca_cnt[inf],com_cnt[inf];
struct query{
    int l,r,id;
}q[inf];
bool cmp(query &a,query &b){
    return id[a.l]^id[b.l] ? id[a.l]<id[b.l] : a.r<b.r;
}
signed main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>n>>m;
    len=sqrt(n);
    bnum=ceil((double)n/len);
    for(int i=1;i<=bnum;++i){
        ls[i]=len*(i-1)+1;
        rs[i]=len*i;
        for(int j=ls[i];j<=rs[i];j++) id[j]=i;
    }
    rs[bnum]=n;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),inp[i]=a[i];
    sort(inp+1,inp+n+1);
    tot=unique(inp+1,inp+n+1)-inp-1;
    for(int i=1;i<=n;i++) col[i]=lower_bound(inp+1,inp+tot+1,a[i])-inp;
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    for(int k=0;k<=bnum;k++){
        l=rs[k]+1,r=rs[k],now=0;
        memset(com_cnt,0,sizeof(com_cnt));
        while(id[q[ic].l]==k){
            ql=q[ic].l,qr=q[ic].r;
            if(id[ql]==id[qr]){
                tmp=0;
                for(int i=ql;i<=qr;i++) sca_cnt[col[i]]=0;
                for(int i=ql;i<=qr;i++) ++sca_cnt[col[i]],tmp=max(tmp,sca_cnt[col[i]]*a[i]);
                ans[q[ic].id]=tmp;
                ic++;
                continue;
            }
            while(r<qr){
                r++;
                com_cnt[col[r]]++;
                now=max(now,com_cnt[col[r]]*a[r]);
            }
            tmp=now;
            while(l>ql){
                l--;
                com_cnt[col[l]]++;
                now=max(now,com_cnt[col[l]]*a[l]);
            }
            ans[q[ic].id]=now;
            while(l<rs[k]+1){
                com_cnt[col[l]]--;
                l++;
            }
            now=tmp;
            ic++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
    return 0;
}