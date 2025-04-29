#include<bits/stdc++.h>
using namespace std;
const int inf=110;
const double eps=1e-6;
int n,opt;
int a[inf][inf];
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
    if(r<=n){
        for(int k=r;k<=n;k++){
            if(a[k][n+1]) return -1;
        }
        return 0;
    }
    for(int i=n;i;i--){
        for(int j=i+1;j<=n;j++){
            a[i][n+1]^=a[i][j]*a[j][n+1];
        }
    }
    return 1;
}
int main(){
    // freopen("a.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    opt=gauss();
    if(opt==1){
        for(int i=1;i<=n;i++){
            printf("%d\n",a[i][n+1]);
        }
    }
    else cout<<opt;
    return 0;
}