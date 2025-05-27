#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=4210;
int n,p,dp[2][inf];
signed main(){
	cin>>n>>p;
	dp[1][1]=1;
	for(int i=2;i<=n;i++) for(int j=1;j<=i;j++) dp[i&1][j]=dp[i&1][j-1]+dp[(i-1)&1][i-j]%p;
	cout<<dp[n&1][n]*2%p;
}
