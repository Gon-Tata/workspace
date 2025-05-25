#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e7+10;
const int mood=999911659;
int n,g;
int fac[5][inf],mo[]={0,2,3,4679,35617,999911659},opt,a[5],ans,kmod;
vector<int> facts;
int get_fac(int x){return fac[opt][x]?fac[opt][x]:fac[opt][x]=get_fac(x-1)*x%mo[opt];}
int Pow(int a,int x){
	// return 0;
	int ans=1,p=mo[opt];
	// cout<<p<<'\n';
	a%=p;
	while(x){
		if(x&1) ans=(1ll*ans*a)%p;
		a=(1ll*a*a)%p;
		x>>=1;
	}
	return ans;
}
int C(int n,int m){
	int p=mo[opt];
	return n<m?0:1ll*get_fac(n)*Pow(get_fac(m),p-2)%p*Pow(get_fac(n-m),p-2)%p;
}
int lucas(int n,int m){
	// return 0;
	int p=mo[opt];
    return m?1ll*lucas(n/p,m/p)%p*C(n%p,m%p)%p:1;
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
int inv(int a,int mod){
	int x,y;
	exgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
int crt(int a[],int m[],int n){
	// return 0;
	// int mul=1;
	// for(int i=1;i<=n;i++) mul*=m[i];
	int mul=mood-1;
	// cout<<mul<<endl;
	int t,c,k=0;
	for(int i=1;i<=n;i++){
		t=mul/m[i];
		c=inv(t,m[i]);
		k=(k+a[i]*t%mul*c%mul)%mul;
	}
	return (k+mul)%mul;
}
void get_facts(){
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			facts.push_back(i);
			if(i*i!=n) facts.push_back(n/i);
		}
	}
}
signed main(){
	cin>>n>>g;
	if(g==mood){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=4;i++) fac[i][0]=1;
	get_facts();
	int len=facts.size();
	for(int i=1;i<=4;i++){
		kmod=mo[i];
		opt=i;
		for(int j=0;j<len;j++){
			a[i]=((a[i]+lucas(n,facts[j]))%kmod+kmod)%kmod;
		}
	}
	ans=crt(a,mo,4);
	opt=5;
	ans=Pow(g,ans);
	cout<<ans<<'\n';
}