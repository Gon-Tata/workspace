#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
int qr,n,l,p;
int q[inf],v[inf],nxt[inf];
char s[inf][35];
long double sum[inf],f[inf];
bool vis[inf];
void clear()
{
    memset(nxt, 0, sizeof(nxt));
    memset(vis, false, sizeof(vis));
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

int main()
{
    freopen("a.in","r",stdin);
    scanf("%d", &qr);
    while (qr--)
    {
        // init();
        // scanf("%d%d%d", &n, &l, &p);
        // for (int i = 1; i <= n; i++)
        // {
        //     scanf("%s", s[i]);
        //     sum[i] = sum[i - 1] + strlen(s[i]) + 1;
        // }
        cin>>n>>l>>p;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]);
            sum[i]=sum[i-1]+strlen(s[i])+1;
        }
        int ql=1, qr=1;
        // q[ql = qr = 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            while ((ql < qr) && (v[ql + 1] <= i)) ql++;
            f[i] = val(q[ql], i), nxt[i] = q[ql];
            while ((ql < qr) && (v[qr] >= query(i, q[qr]))) qr--;
            q[++qr] = i, v[qr] = query(i, q[qr - 1]);
        }
        // for(int i=1;i<=n;i++){
        //     while(ql<qr&&v[ql+1]<=i) ql++;
        //     f[i]=val(q[ql],i);
        //     nxt[i]=q[ql];
        //     while(ql<qr&&v[qr]>=query(i,q[qr])) qr--;
        //     q[++qr]=i;
        //     v[qr]=query(i,q[qr-1]);
        // }
        if (f[n] > 1e18) puts("Too hard to arrange");
        else
        {
            printf("%lld\n", (long long)f[n]);
            for (int i = n; i; i = nxt[i]) vis[i] = true;
            int cur = 1;
            while (cur <= n)
            {
                if (!vis[cur]) printf("%s ", s[cur]);
                else printf("%s\n", s[cur]);
                cur++;
            }
        }
        puts("--------------------");
    }
    return 0;
}