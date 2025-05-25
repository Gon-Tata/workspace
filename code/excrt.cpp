#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e6+10;
int m[inf],a[inf],ans,n;
int qmul(int a,int b,int mod){
	int ans=0,base=a;
	while(b){
		if(b&1) ans=(ans+base)%mod;
		base=(base+base)%mod;
		b>>=1;
	}
	return ans;
}
int qpow(int a,int b,int mod){
	int ans=1,base=a;
	while(b){
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return ans;
}
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int z=x;
	x=y;
	y=z-y*(a/b);
	return d;
}
int excrt(){
	int ans=a[1],M=m[1],x,y;
	for(int i=2;i<=n;i++){
		int mod=m[i],res=((a[i]-ans)%mod+mod)%mod,gcd=exgcd(M,mod,x,y);
		if(res%gcd){
			cout<<-1;
			exit(0);
		}
		x=qmul(x,res/gcd,mod);
		ans+=x*M;
		M*=mod/gcd;
		ans=(ans%M+M)%M;
	}
	return ans;
}
main(){
	// freopen("a.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&m[i],&a[i]);
	cout<<excrt();
}