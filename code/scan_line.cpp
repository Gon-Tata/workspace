#include <bits/stdc++.h>
using namespace std;
#define lson id<<1
#define rson id<<1|1
const int inf = 1e4;
struct lineeeeeeeee
{
    double l;
    double r;
    double h;
    int val;
}lin[inf];
struct treeeeeeeeee
{
    int l,r,sum;
    double len;
}tr[inf<<2];
bool cmp(lineeeeeeeee &a,lineeeeeeeee &b){
    return a.h<b.h;
}
int n,ooo;
double ans,kx[inf];
void build(int id,int l,int r){
    tr[id].l=l;
    tr[id].r=r;
    if(l==r) return ;
    int mid=(l+r)/2;
    build(lson,l,mid);
    build(rson,mid+1,r);
}
void push_up(int id){
    int l=tr[id].l,r=tr[id].r;
    if(tr[id].sum) tr[id].len=kx[r+1]-kx[l];
    else{
        tr[id].len=tr[lson].len+tr[rson].len;
    }
}
void update(int id,double l,double r,int val){
    int kl=tr[id].l,kr=tr[id].r;
    if(kx[kr+1]<=l||kx[kl]>=r) return ;
    if(l<=kx[kl] && r>=kx[kr+1]){
        tr[id].sum+=val;
        push_up(id);
        return ;
    }
    update(lson,l,r,val);
    update(rson,l,r,val);
    push_up(id);
}
void clear(){
    memset(lin,0,sizeof(lin));
    memset(tr,0,sizeof(tr));
    ans=0;
}
int main(){
    // freopen("poj.in","r",stdin);
    // freopen("atlantis1.in","r",stdin);
    // freopen("poj.out","w",stdout);
    while(cin>>n&&n){
        int i=1,xcnt=0,lcnt=0;
        for(double x1,x2,y1,y2;i<=n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            kx[++xcnt]=x1;
            kx[++xcnt]=x2;
            lin[++lcnt]={x1,x2,y1, 1};
            lin[++lcnt]={x1,x2,y2,-1};
        }
        n<<=1;
        sort(lin+1,lin+n+1,cmp);
        sort(kx+1,kx+n+1);
        int cnt=unique(kx+1,kx+n+1)-kx-1;
        build(1,1,cnt-1);
        for(int i=1;i<n;i++){
            update(1,lin[i].l,lin[i].r,lin[i].val);
            ans+=tr[1].len*(lin[i+1].h-lin[i].h);
        }
        printf("Test case #%d\n",++ooo);
        printf("Total explored area: %.2lf\n\n",ans);
        clear();
    }
    return 0;
}

/*

Keep dreaming
Remain loving

*/