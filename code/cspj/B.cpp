#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e5+10;
const int mod=1e9+7;
int n,ans,kmin;
bool o;
int m[inf],a[inf],len[2][inf];
signed main(){
	freopen("14.in","r",stdin);
	// freopen("hole.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&m[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		len[0][i]=a[i]-1;
		len[1][i]=m[i]-a[i];
	}
	// if(n==2){
	// 	ans+=min(len[0][1],len[0][2]);
	// 	ans%=mod;
	// 	ans+=min(len[1][1],len[0][2]);
	// 	ans%=mod;
	// 	ans+=min(len[0][1],len[1][2]);
	// 	ans%=mod;
	// 	ans+=min(len[1][1],len[1][2]);
	// 	ans%=mod;
	// 	ans++;
	// 	cout<<ans;
	// }
	int k;
	for(int i=1;i<=1<<n;i++){
		k=i;
		kmin=LONG_LONG_MAX;
		for(int j=1;j<=n;j++){
			o=k&1;
			// cout<<o;
			kmin=min(kmin,len[o][j]);
			k>>=1;
		}
		// cout<<endl;
		ans+=kmin;
		ans%=mod;
	}
	ans++;
	ans%=mod;
	cout<<ans;

}