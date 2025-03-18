#include<bits/stdc++.h>
using namespace std;
const int inf=1e6+100;
struct jtr{
    int son[26],flag,fail,ans;
}tr[inf/2+100];
int t,n,cnt,tot,ans,vis[inf],in[inf],map[inf];
char s[inf],qq[inf];
queue<int> q;
void ins(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!tr[u].son[v]) tr[u].son[v]=++cnt;
        u=tr[u].son[v];
    }
    if(!tr[u].flag) tr[u].flag=tot;
    map[num]=tr[u].flag;
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
            in[tr[v].fail]++;
            q.push(v);
        }
    }
}
void query(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        u=tr[u].son[v];
        tr[u].ans++;
    }
}
void topu(){
    for(int i=1;i<=cnt;i++) if(in[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[tr[u].flag]=tr[u].ans;
        int v=tr[u].fail;
        in[v]--;
        tr[v].ans+=tr[u].ans;
        if(!in[v]) q.push(v);
    }
}
int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cnt=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        tot++;
        ins(s[i]);
    }
    get_fail();
    scanf("%s",qq);
    query(qq);
    topu();
    for(int i=1;i<=n;i++) cout<<vis[map[i]]<<'\n';
    return 0;
}