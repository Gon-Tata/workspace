#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e5+10;
const int p=1e9+7;
int n,k,fac[inf+2],ans;
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
signed main(){
	// freopen("a.in","r",stdin);
    fac[0]=1;
    for(int i=1;i<=inf;++i) fac[i]=1ll*fac[i-1]*i%p;
    scanf("%lld%lld",&n,&k);
	for(int i=0;i<=min(k,n-1);i++){
		ans=(ans+(C(n,i)*C(n-1,n-i-1))%p+p*2)%p;
	}
	cout<<ans;
    return 0;
}