#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
int t,op,x,y,z,a,b,root,cnt;
struct jtr{
	int val,pri,size,ch[2];
}tr[inf];
inline void updata(int id){
	tr[id].size=tr[tr[id].ch[0]].size+tr[tr[id].ch[1]].size+1;
	return ;
}
inline int new_node(int v){
	tr[++cnt].size=1;
	tr[cnt].val=v;
	tr[cnt].pri=rand();
	return cnt;
}
inline int merge(int x,int y){
	if(!x||!y) return x+y;
	if(tr[x].pri<tr[y].pri){
		tr[x].ch[1]=merge(tr[x].ch[1],y);
		updata(x);
		return x;
	}
	else{
		tr[y].ch[0]=merge(x,tr[y].ch[0]);
		updata(y);
		return y;
	}
}
inline void split(int now,int k,int &x,int &y){
	if(!now) x=y=0;
	else{
		if(tr[now].val<=k){
			x=now;
			split(tr[now].ch[1],k,tr[now].ch[1],y);
		}
		else{
			y=now;
			split(tr[now].ch[0],k,x,tr[now].ch[0]);
		}
		updata(now);
	}
	return ;
}
inline int find(int now,int k){
	while(1){
		if(k<=tr[tr[now].ch[0]].size) now=tr[now].ch[0];
		else{
			if(k==tr[tr[now].ch[0]].size+1) return now;
			else{
				k-=tr[tr[now].ch[0]].size+1;
				now=tr[now].ch[1];
			}
		}
	}
}
inline void ins(){
	split(root,a,x,y);
	root=merge(merge(x,new_node(a)),y);
	return ;
}
inline void del(){
	split(root,a,x,z);
	split(x,a-1,x,y);
	y=merge(tr[y].ch[0],tr[y].ch[1]);
	root=merge(merge(x,y),z);
	return ;
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&op,&a);
		if(op==1){
			ins();
			continue;
		}
		if(op==2){
			del();
			continue;
		}
		if(op==3){
			split(root,a-1,x,y);
			printf("%d\n",tr[x].size+1);
			root=merge(x,y);
			continue;
		}
		if(op==4){
			printf("%d\n",tr[find(root,a)].val);
			continue;
		}
		if(op==5){
			split(root,a-1,x,y);
			printf("%d\n",tr[find(x,tr[x].size)].val);
			root=merge(x,y);
			continue;
		}
		if(op==6){
			split(root,a,x,y);
			printf("%d\n",tr[find(y,1)].val);
			root=merge(x,y);
			continue;
		}
	}
	return 0;
}//https://www.luogu.com.cn/article/nsp2x87a 
//https://www.luogu.com.cn/article/rhatyvht