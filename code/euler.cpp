#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 5e4;
int n,ans;
int phi[inf];
vector <int> pri;
bool not_pri[inf];
void pre(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!not_pri[i]){
            pri.push_back(i);
            phi[i]=i-1;
        }
        for(auto k:pri){
            if(i*k>n) break;
            not_pri[i*k]=1;
            if(i%k==0){
                phi[i*k]=k*phi[i];
                break;
            }
            phi[i*k]=phi[k]*phi[i];
        }
    }
}
signed main(){
    cin>>n;
    if(!n||n==1){
        cout<<0;
        return 0;
    }
    pre(n);
    for(int i=2;i<n;i++) ans+=2*phi[i];
    cout<<ans+3;
    return 0;
}