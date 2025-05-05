#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int inf=1e5+10;
const int base=13331;
int t,la,lb;
int ans;
char a[inf],b[inf];
int hash_a[inf],hash_b[inf],pre[inf];
void pre_(){
	// memset(hash_a,0,sizeof(hash_a));
	// memset(hash_b,0,sizeof(hash_b));
	for(int i=1;i<=la;i++) hash_a[i]=a[i]+hash_a[i-1]*base;
	for(int i=1;i<=lb;i++) hash_b[i]=b[i]+hash_b[i-1]*base;
}
// int get(int l,int r,bool opt){
// 	if(!opt) return hash_a[r]-hash_a[l-1]*pre[r-l+1];
// 	else return hash_b[r]-hash_b[l-1]*pre[r-l+1];
// }
// bool check(int x){
// 	return (get(1,x,0)==get(lb-x+1,lb,1));
// }
void er(){
	int l=0,r=min(la,lb);
	for(int i=r;i>=l;i--){
		if(hash_a[i]==hash_b[lb]-hash_b[lb-i]*pre[i]){
			ans=i;
			break;
		}
	}
}
char s[inf];
signed main(){
	// freopen("b.in","r",stdin);
	freopen("string10.in","r",stdin);
	// freopen("string.out","w",stdout);
	pre[0]=1;
	for(int i=1;i<inf;i++) pre[i]=pre[i-1]*base;
	cin>>t;
	while(t--){
		// memset(s,0,sizeof(s));
		// memset(a,0,sizeof(a));
		// memset(b,0,sizeof(b));
		scanf("%lld%lld",&la,&lb);
		ans=0;
		getchar();
		// if(la>lb) lb++;
		cin>>(a+1);
		for(int i=1;i<=lb;i++){
			b[i]=a[i];
		}
		getchar();
		lb++;
		scanf("%c",&b[lb]);
		pre_();
		er();
		cout<<ans<<'\n';
	}
}