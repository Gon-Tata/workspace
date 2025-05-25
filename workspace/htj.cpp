#include<bits/stdc++.h>
#define ui unsigned int
#define ll long long
#define db double
#define ld long double
#define ull unsigned long long
const int Mod=999911659,MAXN=100000+10,MAXM=40000+10;
int W[5]={0,2,3,4679,35617},num[MAXN],cnt,fac[5][MAXM],inv[5][MAXM],B[5];
template<typename T> inline void read(T &x)
{
	T data=0,w=1;
	char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(ch>='0'&&ch<='9')data=((T)data<<3)+((T)data<<1)+(ch^'0'),ch=getchar();
	x=data*w;
}
template<typename T> inline void write(T x,char ch='\0')
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	if(ch!='\0')putchar(ch);
}
template<typename T> inline void chkmin(T &x,T y){x=(y<x?y:x);}
template<typename T> inline void chkmax(T &x,T y){x=(y>x?y:x);}
template<typename T> inline T min(T x,T y){return x<y?x:y;}
template<typename T> inline T max(T x,T y){return x>y?x:y;}
inline ll qexp(ll a,ll b,ll n)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=res*a%n;
		a=a*a%n;
		b>>=1;
	}
	return res;
}
inline ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-(a/b)*y;
	return r;
}
inline void init(int n)
{
	for(register int i=1,limit=sqrt(n);i<=limit;++i)
		if(n%i==0)num[++cnt]=i,num[++cnt]=n/i;
	std::sort(num+1,num+cnt+1);
	cnt=std::unique(num+1,num+cnt+1)-num-1;
	for(register int t=1;t<=4;++t)
	{
		fac[t][0]=1;
		for(register int i=1;i<W[t];++i)fac[t][i]=1ll*fac[t][i-1]*i%W[t];
		inv[t][W[t]-1]=qexp(fac[t][W[t]-1],W[t]-2,W[t]);
		for(register int i=W[t]-2;i>=0;--i)inv[t][i]=1ll*inv[t][i+1]*(i+1)%W[t];
	}
}
inline ll C(ll n,ll m,ll ps)
{
	if(n<m)return 0;
	if(n<W[ps]&&m<W[ps])return fac[ps][n]*inv[ps][m]%W[ps]*inv[ps][n-m]%W[ps];
	else return C(n/W[ps],m/W[ps],ps)*C(n%W[ps],m%W[ps],ps)%W[ps];
}
inline ll calc(ll a,ll b)
{
	ll x,y;
	exgcd(a,b,x,y);
	return (x+b)%b==0?b:(x+b)%b;
}
inline ll CRT(ll p)
{
	ll res=0;
	for(register int i=1;i<=4;++i)(res+=B[i]*(p/W[i])%p*calc(p/W[i],W[i])%p)%=p;
	return res;
}
int main()
{
	freopen("a.in","r",stdin);
    int n,G;read(n);read(G);
	if(G%Mod==0)
	{
		puts("0");
		return 0;
	}
	init(n);
	for(register int i=1;i<=cnt;++i)
		for(register int j=1;j<=4;++j)(B[j]+=C(n,num[i],j))%=W[j];
    // for(int i=1;i<=4;i++) std::cout<<B[i]<<'\n';
    std::cout<<CRT(Mod-1)<<'\n';
	write(qexp(G,CRT(Mod-1),Mod),'\n');
	return 0;
}