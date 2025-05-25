#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=12;
int n,a[inf],m[inf],t,c,ans;
__int128 k;
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
signed main(){
	// freopen("a.in","r",stdin);
	cin>>n;
	int mul=1;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&m[i],&a[i]);
		mul*=m[i];
	}
	for(int i=1;i<=n;i++){
		t=mul/m[i];
		c=inv(t,m[i]);
		k=(k+(__int128)a[i]*t%mul*c%mul)%mul;
	}
	ans=k;
	cout<<ans;
}