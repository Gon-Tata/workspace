#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e7+10;
int n,len,tot,cnt,ans,kans,sl[inf],sr[inf];
bool a[inf];
char s[inf];
signed main(){
	freopen("d.in","r",stdin);
	// freopen("a.out","w",stdout);
	// freopen("sushi.in","r",stdin);
	// freopen("sushi.out","w",stdout);
	cin>>n;
	while(n--){
		ans=LONG_LONG_MAX;
		cnt=0;
		tot=0;
		cin>>(s+1);
		len=strlen(s+1);
		for(int i=1;i<=len;i++) a[i]=(s[i]=='R');
		for(int i=1;i<=len;i++)	if(a[i]) tot++;
		for(int i=1;i<=len;i++){
			if(a[i]==1){
				cnt++;
				sl[cnt]=i-1+sl[cnt-1]-(cnt-1);
			}
		}
		for(int i=len;i>=1;i--){
			if(a[i]==1){
				sr[cnt]=len-i+sr[cnt+1]-(tot-cnt);
				cnt--;
			}
		}
		for(int i=0;i<=tot;i++)
		{
			// cout<<sl[i]<<' '<<sr[i+1]<<endl;
			kans=sl[i]+sr[i+1];
			ans=min(ans,kans);
		}
		// cout<<ans<<endl;
		// ans=LONG_LONG_MAX;
		// tot=0;
		// cin>>s+1;
		// len=strlen(s+1);
		// for(int i=1;i<=len;i++) a[i]=(s[i]=='R');
		// for(int i=1;i<=len;i++)	if(a[i]) tot++;
		memset(sl,0,sizeof(sl));
		memset(sr,0,sizeof(sr));
		cnt=0;
		tot=len-tot;
		for(int i=1;i<=len;i++){
			if(a[i]==0){
				cnt++;
				sl[cnt]=i-1+sl[cnt-1]-(cnt-1);
			}
		}
		for(int i=len;i>=1;i--){
			if(a[i]==0){
				sr[cnt]=len-i+sr[cnt+1]-(tot-cnt);
				cnt--;
			}
		}
		// cout<<cnt<<endl;
		for(int i=0;i<=tot;i++){
			// cout<<sl[i]<<' '<<sr[i+1]<<endl;
			kans=sl[i]+sr[i+1];
			ans=min(ans,kans);
		}
		cout<<ans<<'\n';
	}
}