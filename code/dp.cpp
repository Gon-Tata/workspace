#include<bits/stdc++.h>
using namespace std;
int d,a[10000];
int main(){
    freopen("d.in","r",stdin);
    for(int i=1;i<=1000;i++) cin>>a[i];
    cin>>d;
    for(int i=1;i<=1000;i++){
        cin>>d;
        if(d!=a[i]) cout<<i<<" myans--> "<<a[i]<<"   trueans--> "<<d<<endl;
    }
}