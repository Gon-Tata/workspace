#include<bits/stdc++.h>
using namespace std;
const int inf=1e6+100;
struct jtr{
    int son[26],flag,fail;
}tr[inf/2+100];
int t,n,cnt,tot,ans,vis[inf];
char s[152][100],qq[inf];
queue<int> q;
void ins(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!tr[u].son[v]) tr[u].son[v]=++cnt;
        u=tr[u].son[v];
    }
    tr[u].flag=tot;
}
void get_fail(){
    for(int i=0;i<26;i++) tr[0].son[i]=1;
    q.push(1);
    tr[1].fail=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            int v=tr[u].son[i];
            int fail=tr[u].fail;
            if(!v){
                tr[u].son[i]=tr[fail].son[i];
                continue;
            }
            tr[v].fail=tr[fail].son[i];
            q.push(v);
        }
    }
}
void query(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        int k=tr[u].son[v];
        while(k>1){
            if(tr[k].flag) vis[tr[k].flag]++;
            k=tr[k].fail;
        }
        u=tr[u].son[v];
    }
}
void clear(){
    memset(tr,0,sizeof(tr));
    memset(vis,0,sizeof(vis));
    tot=0,ans=0;
}
int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    while(1){
        cnt=1;
        scanf("%d",&n);
        if(!n) return 0;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]);
            tot++;
            ins(s[i]);
        }
        get_fail();
        scanf("%s",qq);
        query(qq);
        for(int i=1;i<=n;i++) ans=max(ans,vis[i]);
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++) if(vis[i]==ans) cout<<s[i]<<'\n';
        clear();
    }
    return 0;
}