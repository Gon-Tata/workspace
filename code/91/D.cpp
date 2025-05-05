#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e7+10;
int n,len,tot,cnt,ans,kans,sl[inf],sr[inf],kl,kr;
struct jtr{
	int cnt,val;
};
bool a[inf];
char s[inf];
signed main(){
	// freopen("d.in","r",stdin);
	// freopen("a.out","w",stdout);
	freopen("sushi.in","r",stdout);
	freopen("sushi.out","w",stdout);
	cin>>n;
	while(n--){
		ans=LONG_LONG_MAX;
		tot=0;
		cin>>s+1;
		len=strlen(s+1);
		// cout<<len<<endl;
		for(int i=1;i<=len;i++) a[i]=(s[i]=='R');
		// for(int i=1;i<=len;i++) cout<<a[i];
		for(int i=1;i<=len;i++)	if(a[i]) tot++;
		for(int i=1;i<=len;i++){
			if(a[i]){
				cnt++;
				sl[cnt]=i-1+sl[cnt-1]-(cnt-1);
				// kl=sl[cnt];
				// sl[cnt].cnt=kl.cnt+1;
				// kl.cnt++;
			}
		}
		for(int i=len;i>=1;i--){
			if(a[i]){
				sr[cnt]=len-i+1+sr[cnt+1]-1-(tot-cnt);
				// kr.val=sr[cnt].val;
				cnt--;
				// sl[i].cnt=kl.cnt+1;
				// kl.cnt++;
			}
		}
		// for(int i=1;i<=tot;i++) cout<<sl[i]<<' '<<sr[i]<<'\n';
		for(int i=0;i<=tot;i++){
			// cout<<sl[i]<<' '<<sr[i+1]<<'\n';
			kans=sl[i]+sr[i+1];
			// cout<<kans<<endl;
			ans=min(ans,kans);
		}
		cout<<ans<<'\n';
	}
}