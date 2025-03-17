#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf=110;
const double eps=1e-6;
int t,n,opt,x,y;
int a[inf][inf],b[inf];
int gauss(){
    int i,r;
    for(i=1,r=1;i<=n;i++){
        int t=r;
        for(int k=r;k<=n;k++){
            if(a[k][i]) t=k;
        }
        if(!a[t][i]) continue;
        for(int l=i;l<=n+1;l++) swap(a[t][l],a[r][l]);
        for(int k=r+1;k<=n;k++){
            if(a[k][i])
                for(int l=n+1;l>=i;l--){
                    a[k][l]^=a[r][l];
                }
        }
        r++;
    }
    for(int k=r;k<=n;k++){
        if(a[k][n+1]) return 0;
    }
    return 1<<(n-r+1);
}
int main(){
    // freopen("a.in","r",stdin);
    cin>>t;
    for(int ki=1;ki<=t;ki++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i][n+1]);
            a[i][n+1]^=b[i];
            a[i][i]=1;
        }
        while(scanf("%d%d",&x,&y)&&(x||y)) a[y][x]=1;
        opt=gauss();
        if(!opt) puts("Oh,it's impossible~!!");
        else cout<<opt<<'\n';
        memset(a,0,sizeof(a));
    }
    return 0;
}