#include<bits/stdc++.h>
using namespace std;
const int inf=510;
int n,p[inf],ktot,cnt;
int mp[inf][inf];
bool check(int x,int y){
	if(!x||!y||x>n||y>x) return 0;
	return 1;
}
void dfs(int x,int y,int opt){
	if(!check(x,y)) return ;
	if(!cnt){
		// cout<<opt<<'\n';
		// if(opt==p[n]) cout<<"fghj";
		if(opt==p[n]){
			// cout<<"df";
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++) cout<<mp[i][j]<<' ';
				putchar('\n');
			}
			exit(0);
		}
		cnt=p[++ktot];
		// cout<<ktot<<' '<<p[ktot]<<'\n';
		dfs(ktot,ktot,p[ktot]);
	}
	if(!mp[x][y]){
		mp[x][y]=opt;
		cnt--;
		dfs(x-1,y,opt);
		dfs(x+1,y,opt);
		dfs(x,y-1,opt);
		dfs(x,y+1,opt);
		mp[x][y]=0;
		cnt++;
	}
}
signed main(){
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		// mp[i][i]=p[i];
	}
	cnt=p[++ktot];
	dfs(ktot,ktot,p[1]);
	return 0;
}