#include<bits/stdc++.h>
using namespace std;
const int inf=2e5+10;
int n,a[inf],dp[inf],pd[inf],f[inf];
long long ans;
inline void upd(int i){
	if(n<i) return;
	int in=0,de=n+1;
	if(pd[i-1]<a[i]) in=max(in,a[i-1]);
	if(a[i-1]<a[i]) in=max(in,dp[i-1]);
	if(a[i]<dp[i-1]) de=min(de,a[i-1]);
	if(a[i]<a[i-1]) de=min(de,pd[i-1]);
	if(in==dp[i]&&de==pd[i]) return;
	dp[i]=in;
	pd[i]=de;
	f[i]=0;
	if(de<=n||in){
		upd(i+1);
		f[i]=f[i+1]+1;
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;1<=i;i--){
		dp[i]=n+1;
		pd[i]=0;
		upd(i+1);
		f[i]=f[i+1]+1;
		ans+=f[i];
	}
	cout<<ans<<'\n';
	return 0;
}