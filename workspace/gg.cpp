#include<bits/stdc++.h>
using namespace std;
const int inf=1e6+10;
int t,n,k,ks,kl,ans=1,cnt,p[inf],c[inf];
void clear(){
	ans=1;
	cnt=0;
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
}
signed main(){
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	cin>>t;
	for(int ki=1;ki<=t;ki++){
		scanf("%d",&n);
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0){
				p[++cnt]=i;
				while(n%i==0) n/=i,c[cnt]++;
			}
		}
		if(n>1){
			p[++cnt]=n;
			c[cnt]=1;
		}
		for(int i=1;i<=cnt;i++) ans*=(2*c[i]+1);
		cout<<"Case "<<ki<<": "<<(ans/2+1)<<'\n';
		clear();
	}
}