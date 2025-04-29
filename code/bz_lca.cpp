#include<bits/stdc++.h>
using namespace std;
const int inf=5e5+10;
vector <int> t[inf];
struct jtr{
	int fa[20];
	int deep;
}tr[inf];
int n,m,s,x,y;
int loog[inf];
void get_log(){
    int k=0;
    loog[1]=0;
    for(int i=2;i<=n;i++){
        if(i==1<<(k+1)) k++;
        loog[i]=k;
    }
    return ;
}
void dfs(int x,int fa){
	tr[x].deep=tr[fa].deep+1;
	tr[x].fa[0]=fa;
	for(int i=1;(1<<i)<=tr[x].deep;i++){
		tr[x].fa[i]=tr[tr[x].fa[i-1]].fa[i-1];
	}
	int sz=t[x].size();
	for(int i=0;i<sz;i++){
		if(t[x][i]!=fa) dfs(t[x][i],x);
	}
	return ;
}
int get_lca(int u,int v){
	if(tr[v].deep>tr[u].deep) swap(u,v);
	int temp=tr[u].deep-tr[v].deep;
	for(int i=0;(1<<i)<=temp;i++){
		if((1<<i)&temp) u=tr[u].fa[i];
	}
	if(u==v) return u;
	for(int i=loog[n];i>=0;i--){
		if(tr[u].fa[i]!=tr[v].fa[i]){
			u=tr[u].fa[i];
			v=tr[v].fa[i];
		}
	}
	return tr[u].fa[0];
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
    	scanf("%d%d",&x,&y);
    	t[x].push_back(y);
    	t[y].push_back(x);
	}
    get_log();
    dfs(s,0);
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&x,&y);
    	printf("%d\n",get_lca(x,y));
	}
	return 0;
}