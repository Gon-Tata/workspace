#include<bits/stdc++.h>
using namespace std;
const int inf=1e6+10;
#define root tr[0].son[1]
int cnt=0,n,op,x;
struct splay{
    int val,fa,rec,size,son[2];
}tr[inf];
inline void updata(int x){
    tr[x].size=tr[tr[x].son[0]].size+tr[tr[x].son[1]].size+tr[x].rec;
    return ;
}
inline bool iden(int x){
    return x==tr[tr[x].fa].son[1];
}
inline void connect(int x,int father,int whi){
    tr[father].son[whi]=x;
    tr[x].fa=father;
    return ;
}
void rotate(int x){
    int Y=tr[x].fa,R=tr[Y].fa;
    int Yson=iden(x),Rson=iden(Y);
    connect(tr[x].son[Yson^1],Y,Yson);
    connect(Y,x,Yson^1);
    connect(x,R,Rson);
    updata(Y);updata(x);
}
void splay(int x,int to){
    to=tr[to].fa;
    while(to!=tr[x].fa){
        if(to==tr[tr[x].fa].fa) rotate(x);
        else if(iden(x)==iden(tr[x].fa)){
                rotate(tr[x].fa);
                rotate(x);
        }
        else{
            rotate(x);
            rotate(x);
        }
    }
    return ;
}
int new_node(int v,int fa){
    tr[++cnt].val=v;
    tr[cnt].fa=fa;
    tr[cnt].size=tr[cnt].rec=1;
    // tr[cnt].son[0]=tr[cnt].son[1]=0;
    return cnt;
}
void ins(int v){
    int now=root;
    if(!root){
        new_node(v,0);
        root=cnt;
        // return ;
    }
    else{
        while(1){
            tr[now].size++;
            if(tr[now].val==v){
                tr[now].rec++;
                splay(now,root);
                return ;
            }
            bool nxt=!(v<tr[now].val);
            if(!tr[now].son[nxt]){
                int p=new_node(v,now);
                tr[now].son[nxt]=p;
                splay(p,root);
                return ;
            }
            now=tr[now].son[nxt];
        }
    }
    return ;
}
int find(int v){
    int now=root;
    while(1){
        if(!now) return 0;
        if(tr[now].val==v){
            splay(now,root);
            return now;
        }
        bool nxt=!(v<tr[now].val);
        // if(!tr[now].son[nxt]) return 0;
        now=tr[now].son[nxt];
    }
}
void del(int v){
    int pos=find(v);
    if(!pos) return ;
    if(tr[pos].rec>1){
        tr[pos].rec--;
        tr[pos].size--;
        return ;
    }
    if(!tr[pos].son[0]&&!tr[pos].son[1]){
        root=0;
        return ;
    }
    if(!tr[pos].son[0]&&tr[pos].son[1]){
        root=tr[pos].son[1];
        // 
        tr[root].fa=0;
        // 
        return ;
    }
    // if(tr[pos].son[0]&&!tr[pos].son[1]){
    //     root=tr[pos].son[0];
    //     return ;
    // } 
    int max=tr[pos].son[0];
    while(tr[max].son[1]) max=tr[max].son[1];
    splay(max,tr[pos].son[0]);
    // tr[max].fa=0;
    connect(tr[pos].son[1],max,1);
    connect(max,0,1);
    updata(max);
    return ;
}
int find_rank(int v){
    int pos=find(v);
    return tr[tr[pos].son[0]].size+1;
}
int kth(int k){
    int now=root;
    while(1){
        int used=tr[now].size-tr[tr[now].son[1]].size;
        if(k>tr[tr[now].son[0]].size && k<=used) break;
        if(k<used) now=tr[now].son[0];
        else{
            k-=used;
            now=tr[now].son[1];
        }
    }
    splay(now,root);
    return tr[now].val;
}
// int pre(int v){
//     int now=root;
//     int ans=-INT_MAX;
//     while(now){
//         if(tr[now].val<v&&tr[now].val>ans) ans=tr[now].val;
//         if(tr[now].val>v) now=tr[now].son[0];
//         else now=tr[now].son[1];
//     }
//     return ans;
// }
// int suc(int v){
//     int now=root;
//     int ans=INT_MAX;
//     while(now){
//         if(tr[now].val>v&&tr[now].val<ans) ans=tr[now].val;
//         if(tr[now].val<v) now=tr[now].son[1];
//         else now=tr[now].son[0];
//     }
//     return ans;
// }
int pre(int x)
{
    int now=root,ans=-INT_MAX;
    while(now)
    {
        if(tr[now].val<x) ans=max(ans,tr[now].val);
        int nxt=x<=tr[now].val?0:1;//这里需要特别注意 
        now=tr[now].son[nxt];
    }
    return ans;
}
int suc(int x)
{
    int now=root,ans=INT_MAX;
    while(now)
    {
        if(tr[now].val>x) ans=min(ans,tr[now].val);
        int nxt=x<tr[now].val?0:1;
        now=tr[now].son[nxt];
    }
    return ans;
}
int main(){
    // freopen("input4.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        // cout<<i<<endl;
        scanf("%d%d",&op,&x);
        if(op==1){
            ins(x);
        }
        if(op==2){
            del(x);
        }
        if(op==3){
            printf("%d\n",find_rank(x));
        }
        if(op==4){
            printf("%d\n",kth(x));
        }
        if(op==5){
            printf("%d\n",pre(x));
        }
        if(op==6){
            printf("%d\n",suc(x));
        }
    }
    return 0;
}