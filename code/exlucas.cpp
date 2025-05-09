#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e6+10;
int n,m,moooood,now,a[inf],p[inf];
void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;
		y=0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
int Pow(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return ans;
}
int inv(int a,int p){
	int x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
int fac(int n,int p,int pk){
	if(n==0) return 1;
	int ans=1;
	for(int i=1;i<=pk;i++) if(i%p) ans=ans*i%pk;
	ans=Pow(ans,n/pk,pk);
	for(int i=1;i<=n%pk;i++) if(i%p) ans=ans*i%pk;
	return  ans*fac(n/p,p,pk)%pk;
}
int C(int n,int m,int p,int pk){
	if(!n||!m||n==m) return 1;
	if(n<m) return 0;
	int nn=fac(n,p,pk),mm=fac(m,p,pk),nm=fac(n-m,p,pk),cnt=0,k=n-m;
	while(n) n/=p,cnt+=n;
	while(m) m/=p,cnt-=m;
	while(k) k/=p,cnt-=k;
	return nn*inv(mm,pk)%pk*inv(nm,pk)%pk*Pow(p,cnt,pk)%pk;
}
int exlucas(int n,int m,int pk){
	int mod=pk;
	for(int i=2;pk!=1;i++){
		if(pk%i) continue;
		int tmp=1;
		p[++now]=i;
		while(!(pk%i)) pk/=i,tmp*=i;
		a[now]=C(n,m,p[now],tmp);
		p[now]=tmp;
	}
	int ans=0;
	for(int i=1;i<=now;i++) ans=(ans+(((mod/p[i]*a[i])%mod)*inv(mod/p[i],p[i])%mod))%mod;
	return ans;
}
signed main(){
	// freopen("a.in","r",stdin);
	cin>>n>>m>>moooood;
	cout<<exlucas(n,m,moooood);
}