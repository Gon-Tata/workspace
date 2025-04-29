#include<bits/stdc++.h>
using namespace std;
const int n_inf=1e6+100;
const int e_inf=1e6+100;
// char buf[1 << 20], *_now = buf, *_end = buf;
// #define getchar() (_now == _end && (_end = (_now = buf) + fread(buf, 1, 1 << 20, stdin), _now == _end) ? EOF : *_now++)
inline int read() {
	int x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c ^ 48), c = getchar());
	return x;
}
int n,m,ql,qr,qt,now,len,knum,cntq,time_tag;
int a[n_inf],id[n_inf],cnt[n_inf],ans[n_inf];
char opt;
struct query{
    int l,r,time,id;
}q[n_inf];
struct modify{
    int pos,color;
}e[e_inf];
inline bool cmp(query &a,query &b){
    return (id[a.l]^id[b.l]) ? id[a.l]<id[b.l] : ((id[a.r]^id[b.r]) ? id[a.r]<id[b.r] : a.time<b.time);
}
int main(){
    freopen("a14.in","r",stdin);
    freopen("a.out","w",stdout);
    int l,r,ktime=0;
    n=read();
    m=read();
    // cout<<n;
    len=pow(n,2.0/3.0);
    knum=ceil((double)n/len);
    for(int i=1;i<=knum;i++){
        for(int j = (i - 1) * len + 1; j <= i * len; ++j) id[j] = i;
    }
    // cout<<len;
    for(int i=1;i<=n;++i) a[i]=read();
    // int kkk=0;
    for(int i=1;i<=m;++i){
        scanf("\n%c",&opt);
        // if(opt=='R') kkk++;
        if(opt=='Q'){
            ++cntq;
            // scanf("%d%d",&q[cntq].l,&q[cntq].r);
            q[cntq].l=read();
            q[cntq].r=read();
            q[cntq].time=time_tag;
            q[cntq].id=cntq;
            continue;
        }
        ++time_tag;
        // scanf("%d%d",&e[time_tag].pos,&e[time_tag].color);
        e[time_tag].pos=read();
        e[time_tag].color=read();
    }
    // cout<<kkk<<"\n\n";
    sort(q+1,q+cntq+1,cmp);
    l=1,r=0;
    for(int i=1;i<=cntq;i++){
        ql=q[i].l,qr=q[i].r,qt=q[i].time;
        while(l<ql) now -= !--cnt[a[l++]];
        while(l>ql) now += !cnt[a[--l]]++;
        while(r<qr) now += !cnt[a[++r]]++;
        while(r>qr) now -= !--cnt[a[r--]];
        while(ktime<qt){
            ++ktime;
            if(ql<=e[ktime].pos && e[ktime].pos<=qr) now-= !--cnt[a[e[ktime].pos]] - !cnt[e[ktime].color]++;
            swap(a[e[ktime].pos],e[ktime].color);
        }
        while(ktime>qt){
            if(ql<=e[ktime].pos && e[ktime].pos<=qr) now-= !--cnt[a[e[ktime].pos]] - !cnt[e[ktime].color]++;
            swap(a[e[ktime].pos],e[ktime].color);
            --ktime;
        }
        ans[q[i].id]=now;
    }
    for(int i=1;i<=cntq;i++) cout<<ans[i]<<'\n';
}