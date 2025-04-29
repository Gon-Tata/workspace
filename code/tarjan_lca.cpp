#include<bits/stdc++.h>
using namespace std;
const int inf=5e5+100;
vector <int> e[inf];
int n,m,s,a,b;
vector <pair<int,int>> q[inf];
int fa[inf],ans[inf];
bool vis[inf];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void tarjan(int x){
	vis[x]=1;
	for(auto y : e[x]){
		if(!vis[y]){
			tarjan(y);
			fa[y]=x;
		}
	}
	for(auto o : q[x]){
		int y=o.first,i=o.second;
		if(vis[y]) ans[i]=find(y);
	}
}
int main(){
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		q[a].push_back({b,i});
		q[b].push_back({a,i});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	tarjan(s);
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}