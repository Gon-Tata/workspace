#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
int n,m,l,r,f[inf][20];
int loog[inf];
void pre(){
    loog[1]=0;
    loog[2]=1;
    for(int i=3;i<=n;i++) loog[i]=loog[i>>1]+1;
}
int main(){
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&f[i][0]);
    pre();
    int loogmax=loog[n];
    for(int o=1;o<=loogmax;o++){
        for(int p=1;p<=n-(1<<o)+1;p++){
            f[p][o]=max(f[p][o-1],f[p+(1<<(o-1))][o-1]);
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&l,&r);
        int s=loog[r-l+1];
        printf("%d\n",max(f[l][s],f[r-(1<<s)+1][s]));
    }
}