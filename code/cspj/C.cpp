#include<bits/stdc++.h>
using namespace std;
const int inf=3010;
int n,m,q,r,k,cnt;
// int a1[inf],b1[inf],a2[inf],b2[inf];
int mp[inf][inf];
struct jtr{
    int t;
    int x;
    int y;
};
queue<jtr>s;
queue<jtr>g;
// bool operator<(C &a,C&b){return a.a<b.a;}
inline bool nxt_tree(int x,int y){return (((mp[x-1][y]==1)||(mp[x+1][y]==1)||(mp[x][y-1]==1)||(mp[x][y+1]==1)));}
inline bool nxt_lake(int x,int y){return ((mp[x][y]==0)&&((mp[x-1][y]==-1)||(mp[x+1][y]==-1)||(mp[x][y-1]==-1)||(mp[x][y+1]==-1)));}
void make_tree(int t,int x,int y)
{
    if (nxt_lake(x + 1, y))
    {
        mp[x + 1][y] = 1;
        // make_tree(x + 1,y);
        g.push({t+1,x + 1,y});
        // cnt++;
    }
    if (nxt_lake(x - 1, y))
    {
        mp[x - 1][y] = 1;
        // make_tree(x - 1,y);
        g.push({t+1,x - 1,y});
        // cnt++;
    }
    if (nxt_lake(x, y + 1))
    {
        mp[x][y + 1] = 1;
        // make_tree(x,y+1);
        g.push({t+1,x,y+1});
        // cnt++;
    }
    if (nxt_lake(x, y - 1))
    {
        mp[x ][y - 1] = 1;
        // make_tree(x,y-1);
        g.push({t+1,x,y-1});
        // cnt++;
    }
    return ;
}
signed main()
{
    freopen("1.in","r",stdin);
	// freopen("lake.out","w",stdout);
    cin>>n>>m>>q>>r>>k;
    for(int i=1,a1,b1,a2,b2;i<=q;i++){
        scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
        for(int j=a1;j<=a2;j++){
            mp[j][b1]=-1;
            mp[j][b2]=-1;
        }
        for(int j=b1;j<=b2;j++){
            mp[a1][j]=-1;
            mp[a2][j]=-1;
        }
    }
    int t,x,y;
    while(1){
        if(r){
            scanf("%d%d%d",&t,&x,&y);
            s.push({t,x,y});
            mp[x][y]=1;
            make_tree(t,x,y);
            r--;
            make_tree(s.front().t,s.front().x,s.front().y);
            if(s.size()>1){
                // cout<<s.front().x<<endl;
                while(t>s.front().t+k-1){
                    if(nxt_tree(s.front().x,s.front().y)||nxt_lake(s.front().x,s.front().y)){
                        cnt++;
                        s.pop();
                    }
                    else{
                        mp[s.front().x][s.front().y]=0;
                        s.pop();
                    }
                }
            }
        }
        else{
            make_tree(s.front().t,s.front().x,s.front().y);
            if(nxt_tree(s.front().x,s.front().y)||nxt_lake(s.front().x,s.front().y)){
                cnt++;
                s.pop();
            }
            else{
                mp[s.front().x][s.front().y]=0;
                s.pop();
            }
        }
        if(s.empty()) break;
    }
    cout<<cnt;
}

/*
-1 lake
0 land
1 tree
support
*/