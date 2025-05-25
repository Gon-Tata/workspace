#include<bits/stdc++.h>
using namespace std;
const int inf=510;
int n,p[inf],mp[inf][inf],cnt;
void sol(int i){
	mp[i][i]=p[i];
	cnt=p[i]-1;
	int x=i,y=i;
	while(cnt){
		while(y>1&&!mp[x][y-1]&&cnt){
			mp[x][--y]=p[i];
			cnt--;
		}
		if(x<n&&!mp[x+1][y]&&cnt){
			mp[++x][y]=p[i];
			cnt--;
		}
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) sol(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<mp[i][j]<<' ';
		}
		putchar('\n');
	}
}