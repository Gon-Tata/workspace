#include<bits/stdc++.h>
using namespace std;
const int inf=5e5+10;
int n,m,a[inf],c[inf],x,y,k,op;
inline int lowbit(int x){
	return x&-x;
}
inline int get(int x){
	int ans=0;
	while(x>0){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void add(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
	return ;
}
int query(int x,int y){
	return get(y)-get(x-1);
}
int main()
{
//	freopen("T.in","r",stdin);
//	freopen("T.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&k);
			add(x,k);
			continue;
		}
		if(op==2){
			scanf("%d",&x);
			printf("%d\n",query(x,y));
			continue;
		}
	}
	return 0;
}