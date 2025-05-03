#include<bits/stdc++.h>
using namespace std;
const int p=1e4+7;
int t,n,m,fac[p+2];
// int Pow(int x,int y){
//     int res=1;
//     for(;y;y>>=1,x=1ll*x*x%p)
//         if(y&1) res=1ll*res*x%p;
//     return res;
// }
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
    cin>>t;
    fac[0]=1;
    for(int i=1;i<=p;++i) fac[i]=1ll*fac[i-1]*i%p;
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%d\n",lucas(n,min(m,n-m)));
    }
    return 0;
}