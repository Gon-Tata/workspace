#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int inf=1e5+10;
int n,ans,cnt;
long long maxn;
// int a[inf],b[inf];
int c[inf<<1];
int a,b;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("bamboo.in","r",stdin);
	freopen("bamboo.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		// s.insert(b);
		// s.insert(a-b);
		c[++cnt]=b;
		c[++cnt]=a-b;
	}
	// int maxn=*s.end();
	// s.erase(maxn);
	// maxn+=*s.end();
	sort(c+1,c+2*n+1,cmp);
	maxn=c[1]+c[2];
	cout<<maxn;
}
//octo