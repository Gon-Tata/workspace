#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=105;
// const int mod=1e9+7;
int n,mod;
struct mat{
	int n;
	int m;
	int val[inf][inf];
	mat(){n=m=0;memset(val,0,sizeof(val));}
}a,o;
mat operator*(const mat &a,const mat &b){
	mat c;
	c.n=a.n;
	c.m=b.m;
	int l=a.m;
	for(int i=1;i<=c.n;i++){
		for(int j=1;j<=c.m;j++){
			for(int k=1;k<=l;k++){
				c.val[i][j]=(c.val[i][j]+1ll*a.val[i][k]*b.val[k][j])%mod;
			}
		}
	}
	return c;
}
mat Pow(mat a,int k){
	if(k==1) return a;
	mat c=Pow(a,k/2);
	c=c*c;
	if(k&1) c=c*a;
	return c;
}
void init(mat &s){
	// cin>>s.n>>s.m;
	for(int i=1;i<=s.n;i++){
		for(int j=1;j<=s.m;j++){
			scanf("%lld",&s.val[i][j]);
		}
	}
}
void write(mat s){
	for(int i=1;i<=s.n;i++){
		for(int j=1;j<=s.m;j++){
			cout<<s.val[i][j]%mod<<' ';
		}
		cout<<'\n';
	}
}
void copy(mat &s,int k[inf][inf]){
	for(int i=1;i<=s.n;i++){
		for(int j=1;j<=s.m;j++){
			s.val[i][j]=k[i][j];
		}
	}
}
int ko[inf][inf]={
	{0,0,0,0,0},
	{0,1,0,0,0},
	{0,1,1,0,0},
	{0,0,0,0,1},
	{0,0,1,1,1}
};
int ka[inf][inf]={
	{0,0,0,0,0},
	{0,0,1,1,1}
};
signed main(){
	// freopen("a.in","r",stdin);
	cin>>n>>mod;
	if(n==1){
		cout<<1;
		return 0;
	}
	o.n=o.m=4;
	a.n=1;
	a.m=4;
	copy(o,ko);
	copy(a,ka);
	o=Pow(o,n-1);
	// write(o);
	a=a*o;
	// write(a);
	cout<<((1ll*n*a.val[1][2]%mod-a.val[1][1])%mod+mod)%mod;
}