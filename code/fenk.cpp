#include<bits/stdc++.h>
using namespace std;
const int inf=5e4+10;
int t,n,x,y,ans,len;
int id[inf],a[inf],s[inf],tag[inf];
string ks;
void add(int l,int r,int v){
    int lid=id[l],rid=id[r];
    if(lid==rid){
        for(int i=l;i<=r;i++){
            a[i]+=v;
            s[lid]+=v;
        }
        return ;
    }
    for(int i=l;id[i]==lid;i++){
        a[i]+=v;
        s[lid]+=v;
    }
    for(int i=lid+1;i<rid;i++){
        tag[i]+=v;
        s[i]+=len*v;
    }
    for(int i=r;id[i]==rid;i--){
        a[i]+=v;
        s[rid]+=v;
    }
}
int query(int l,int r){
    int lid=id[l],rid=id[r];
    ans=0;
    if(lid==rid){
        for(int i=l;i<=r;i++) ans+=(a[i]+tag[lid]);
        return ans;
    }
    for(int i=l;id[i]==lid;i++) ans+=(a[i]+tag[lid]);
    for(int i=lid+1;i<rid;i++) ans+=s[i];
    for(int i=r;id[i]==rid;i--) ans+=(a[i]+tag[rid]);
    return ans;
}
void clear(){
    memset(s,0,sizeof(s));
    memset(tag,0,sizeof(tag));
}
int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>t;
    for(int ki=1;ki<=t;ki++){
        clear();
        cin>>n;
        len=sqrt(n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            id[i]=(i-1)/len+1;
            s[id[i]]+=a[i];
        }
        cout<<"Case "<<ki<<":\n";
        while(cin>>ks){
            if(ks[0]=='E') break;
            scanf("%d %d",&x,&y);
            if(ks[0]=='A'){
                add(x,x,y);
                continue;
            }
            if(ks[0]=='S'){
                add(x,x,-y);
                continue;
            }
            if(ks[0]=='Q'){
                cout<<query(x,y)<<'\n';
            }
        }
    }
}