#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
signed main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) ans+=(i+n/i*i)*(n/i)/2;
	cout<<ans;
}