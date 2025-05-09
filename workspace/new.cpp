#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e6+10;
const int p=1e9+7;
int n,m,fac[inf+2];
int Pow(int a,int x){
	int ans=1;
	a%=p;
	while(x){
		if(x&1) ans=(1ll*ans*a)%p;
		a=(1ll*a*a)%p;
		x>>=1;
	}
	return ans;
}
int C(int a,int b){
    return a<b?0:1ll*fac[a]*Pow(fac[b],p-2)%p*Pow(fac[a-b],p-2)%p;
}
int lucas(int a,int b){
    return b?1ll*lucas(a/p,b/p)%p*C(a%p,b%p)%p:1;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=p;++i) fac[i]=1ll*fac[i-1]*i%p;
	cin>>n>>m;

}
/*

*/
