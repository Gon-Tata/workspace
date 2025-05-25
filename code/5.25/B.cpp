#include<bits/stdc++.h>
using namespace std;
const int inf=1e4+10;
int x,y,z,n,m,t;
int h[inf],to[inf],nxt[inf],w[inf],tot=0,dis[inf],kdis[inf];
bool vis[inf];
queue<int>q;
struct jtr{
	int to;
	int id[2];
	int val;
};
vector<jtr> ke;
void addedge(int x,int y,int z){
	to[++tot]=y;
	nxt[tot]=h[x];
	w[tot]=z;
	h[x]=tot;
	if(x==1) ke.push_back((jtr){y,{tot,tot+1},z});
}
void spfa(int x){
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	q.push(x);
	while(q.size()){
		x=q.front();
		q.pop();
		vis[x]=false;
		for(int i=h[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				if(!vis[y])q.push(y);
			}
		}
	}
}
void clear(){
	ke.clear();
		tot=0;
		memset(h,0,sizeof(h));
		// memset(to,0,sizeof(to));
		// memset(nxt,0,sizeof(nxt));
		// memset(w,0,sizeof(w));
		memset(vis,0,sizeof(vis));
}
int main(){
	// freopen("a.in","r",stdin);
	freopen("leave1.in","r",stdin);
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
			addedge(y,x,z);
		}
		int siz=ke.size();
		spfa(1);
		int ans=INT_MAX;
		for(int i=1;i<=n;i++) kdis[i]=dis[i];
		for(int i=0;i<siz;i++){
			w[ke[i].id[0]]=w[ke[i].id[1]]=0x3f3f3f3f;
			spfa(1);
			ans=min(ans,dis[ke[i].to]+kdis[ke[i].to]);
			w[ke[i].id[0]]=w[ke[i].id[1]]=ke[i].val;
		}
		if(ans>=0x3f3f3f3f) cout<<-1<<'\n';
		else printf("%d\n",ans);
		clear();
	}
	return 0;
}//954