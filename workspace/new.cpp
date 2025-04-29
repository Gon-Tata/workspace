#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
int t,n,l,p,ql=1,qr=1,cnt;
int q[inf],v[inf],nxt[inf];
char s[inf][35];
long double sum[inf],f[inf];
bool vis[inf];
void clear(){
    ql=qr=cnt=1;
    memset(nxt,0,sizeof(nxt));
    memset(vis,0,sizeof(vis));
}
long double qpow(long double a,int k){
    long double ans=1;
    while(k){
        if(k&1) ans*=a;
        a*=a;
        k>>=1;
    }
    return ans;
}
long double val(int i,int j){return f[i]+qpow(abs(sum[j]-sum[i]-l-1),p);}
int query(int p,int q){
    int kl=max(p,q),kr=n,mid;
    while(kl<kr){
        mid=(kl+kr)>>1;
        if(val(p,mid)<=val(q,mid)) kr=mid;
        else kl=mid+1;
    }
    if(kr==n) return n+(val(p,n)>val(q,n));
    return kr;
}
signed main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>l>>p;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]);
            sum[i]=sum[i-1]+strlen(s[i])+1;
        }
        for(int i=1;i<=n;i++){
            while(ql<qr&&v[ql+1]<=i) ql++;
            f[i]=val(q[ql],i);
            nxt[i]=q[ql];
            while(ql<qr&&v[qr]>=query(i,q[qr])) qr--;
            q[++qr]=i;
            v[qr]=query(i,q[qr-1]);
        }
        if(f[n]>1e18) puts("Too hard to arrange");
        else{
            printf("%lld\n",(long long)f[n]);
            for(int i=n;i;i=nxt[i]) vis[i]=1;
            cnt=1;
            while(cnt<=n){
                if(!vis[cnt]) printf("%s ",s[cnt]);
                else printf("%s\n",s[cnt]);
                cnt++;
            }
        }
        puts("--------------------");
        clear();
    }
    y1;
    return 0;
}