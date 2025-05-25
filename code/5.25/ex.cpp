#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int maxm=maxn;
const int inf=0x7f7f7f7f;
int x,y,z,n,m,t;
int h[maxn],to[maxm],nxt[maxm],w[maxm],tot=0,dis[maxn],kdis[maxn];
bool vis[maxn];
queue<int>q;
struct jtr{
	int to;
	int id;
	int val;
};
vector<jtr> ke;
void addedge(int x,int y,int z){
	to[++tot]=y;
	nxt[tot]=h[x];
	w[tot]=z;
	h[x]=tot;
	if(x==1) ke.push_back((jtr){y,tot,z});
	// if(y==1) ke.push_back((jtr){x,tot,z});
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
		memset(to,0,sizeof(h));
		memset(nxt,0,sizeof(h));
		memset(w,0,sizeof(h));
		memset(vis,0,sizeof(vis));
}
int main(){
	// freopen("a.in","r",stdin);
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
			addedge(y,x,z);
			// if(x==1) ke.push_back(y);
			// if(y==1) ke.push_back(x);
		}
		int siz=ke.size();
		// for(int i=0;i<siz;i++) cout<<ke[i].to<<'\n';
		spfa(1);
		int ans=INT_MAX;
		// for(int i=1;i<=n;i++){
		// 	cout<<dis[i]<<'\n';
		// 	if(dis[i]==0x3f3f3f3f){
		// 		printf("-1");
		// 		return 0;
		// 	}
		// 	if(ans<dis[i]) ans=dis[i];
		// }
		for(int i=1;i<=n;i++) kdis[i]=dis[i];
		// for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
		// cout<<'\n';
		// cout<<siz<<'\n';
		for(int i=0;i<siz;i++){
			w[ke[i].id]=0x3f3f3f3f;
			spfa(1);
			ans=min(ans,dis[ke[i].to]+kdis[ke[i].to]);
			w[ke[i].id]=ke[i].val;
		}
		if(ans>=0x3f3f3f3f) cout<<-1<<'\n';
		else printf("%d\n",ans);
		clear();
	}
	return 0;
}
