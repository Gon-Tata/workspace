#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e4+10;
int n,tot,t;
signed main(){
    freopen("a.in","w",stdout);
    for(int i=1;i<=inf;i++){
        tot=0;
        for(int j=1;j<=i;j++){
            if(i%j==0) tot++;
        }
        cout<<tot<<',';
    }
}