#include<bits/stdc++.h>
using namespace std;
const int inf=1e6+10;
int n,cnt,root,opt,x;
struct treap{
    int val,son[2],cer,size,pri;
}tr[inf];
inline void push_up(int id){
    tr[id].size=tr[tr[id].son[0]].size+tr[tr[id].son[1]].size+tr[id].cer;
}
inline int new_node(int v){
    tr[++cnt].val=v;
    tr[cnt].cer=tr[cnt].size=1;
    tr[cnt].pri=rand();
    tr[cnt].son[0]=tr[cnt].son[1]=0;
    return cnt;
}
void rotate(int &r,bool m){
    int kb=tr[r].son[m^1];
    tr[r].son[m^1]=tr[kb].son[m];
    tr[kb].son[m]=r;
    push_up(r);
    push_up(kb);
    r=kb;
}
void ins(int &p,int v){
    if(!p){
        p=new_node(v);
        return ;
    }
    tr[p].size++;
    if(tr[p].val==v){
        tr[p].cer++;
        // tr[p].size++;
        return ;
    }
    bool nxt=(v>tr[p].val);
    ins(tr[p].son[nxt],v);
    if(tr[p].pri>tr[tr[p].son[nxt]].pri) rotate(p,nxt^1);
    push_up(p);
}
void del(int &p,int v){
    if(!p) return ;
    if(tr[p].val<v){
        del(tr[p].son[1],v);
    }
    else if(tr[p].val>v){
        del(tr[p].son[0],v);
    }
    else{
        if(!tr[p].son[0] && !tr[p].son[1]){
            // if(tr[p].cer>1){
                tr[p].cer--;
                tr[p].size--;
                if(!tr[p].cer) p=0;
            // }
        }
        else if(!tr[p].son[0] && tr[p].son[1]){
            rotate(p,0);
            del(tr[p].son[0],v);
        }
        else if(tr[p].son[0] && !tr[p].son[1]){
            rotate(p,1);
            del(tr[p].son[1],v);
        }
        else if(tr[p].son[0] && tr[p].son[1]){
            bool nxt=(tr[tr[p].son[0]].pri>tr[tr[p].son[1]].pri);
            rotate(p,nxt);
            del(tr[p].son[nxt],v);
        }
    }
    push_up(p);
}
int Rank(int p,int v){
    if(!p) return 0;
    if(tr[p].val==v) return tr[tr[p].son[0]].size+1;
    if(tr[p].val<v) return tr[tr[p].son[0]].size+tr[p].cer+Rank(tr[p].son[1],v);
    if(tr[p].val>v) return Rank(tr[p].son[0],v);
    return 0;
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
    return tr[now].val;
}
int pre(int p,int v){
    if(!p) return -inf;
    if(tr[p].val>=v) return pre(tr[p].son[0],v);
    else return max(tr[p].val,pre(tr[p].son[1],v));
}
int suc(int p,int v){
    if(!p) return inf;
    if(tr[p].val<=v) return suc(tr[p].son[1],v);
    else return min(tr[p].val,suc(tr[p].son[0],v));
}
int main(){
    // freopen("P3369_4.in","r",stdin);
    // freopen("a.out","w",stdout);
    srand(time(NULL));
    cin>>n;
    // cout<<n<<endl;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&opt,&x);
        // cout<<opt<<" "<<x<<endl;
        if(opt==1){
            ins(root,x);
            // cout<<root<<endl;
            continue;
        }
        if(opt==2){
            del(root,x);
            continue;
        }
        if(opt==3){
            // cout<<root;
            printf("%d\n",Rank(root,x));
            continue;
        }
        if(opt==4){
            printf("%d\n",kth(x));
            continue;
        }
        if(opt==5){
            // cout<<"FIVE";
            printf("%d\n",pre(root,x));
            continue;
        }
        if(opt==6){
            // cout<<root<<endl;
            printf("%d\n",suc(root,x));
            continue;
        }
    }
    // cout<<endl;
    // cout<<root<<" "<<tr[2].val<<" "<<tr[3].val;
    return 0;
}