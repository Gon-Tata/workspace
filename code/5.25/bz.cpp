#include <bits/stdc++.h>
using namespace std ; 

// 0x21 树与图的遍历 
void dfsxu(){/*  dfs序 
void dfs( int x ) 
{
	a[++m] = x ; 
	v[x] = 1 ; 
	for ( int i = head[x] ; i ; i = nxt[i] )
	{
		int y = ver[x] ; 
		if ( v[y] ) continue ; 
		dfs(y) ; 
	}
	a[++m] = x ; 
*/ 
}
void deep(){/*  树的深度
void dfs( int x )
{
	v[x] = 1 ; 
	for ( int i = head[x] ; i ; i = nxt[i] )
	{
		int y = ver[i] ;
		if ( v[y] ) continue ; 
		d[y] = d[x] + 1 ;
		dfs(y) ; 
	}	
} 
*/ 
}
void zhongxin(){/* 树的重心
void dfs( int x )
{
	v[x] = 1 , size[x] = 1 ; 
	int max_part = 0 ; 
	for ( int i = head[x] ; i ; i = nxt[i] )
	{
		int y = ver[y] ; 
		if ( v[y] ) continue ; 
		dfs(y) ; 
		size[x] += size[y] ; 
		max_part = max( max_part , size(y) ) ; 
	 }
	 max_part = max( max_part , n - size[x] ) ; 
	 if ( max_part < ans )
	 {
	 	ans = max_part ; 
		pos = x ;  	
	 }  	
}	*/
}
void bfs(){/* 广度优先搜索 
void bfs() 
{
	memset( d , 0 , sizeof(d) ) ; 
	queue<int> q ; 
	q.push(1) ; d[1] = 1 ; 
	while ( q.size() > 0 ) 
	{
		int x = q.front() ; q.pop() ; 
		for ( int i = head[x] ; i ; i = nxt[i] )
		{
			int y = ver[i] ; 
			if ( d[y] ) continue ; 
			d[y] = d[x] + 1 ; 
			q.push(y) ; 
		}
	}
} */
}
void add(){/* 加边
void add( int x , int y )
{
	nxt[++tot] = head[x] ;
	ver[tot] = y ;
	head[x] = tot ; 
} */
}
void tuopu(){/* 拓扑排序 
void topsort()
{
	queue<int> q ; 
	for ( int i = 1 ; i <= n ; i ++ ) 
		if ( deg[i] == 0 ) q.push(i) ; // deg是入度 
	while ( q.size() )
	{
		int x = q.front() ; q.pop() ; 
		a[++cnt] = x ; 
		for ( int i = head[x] ; i ; i = nxt[i] )
		{
			int y = ver[i] ; 
			if ( --deg[y] == 0 ) q.push(y) ; 	
		}	
	} 
}*/
}
void prime(){/* 判断素数 

void prime(){
	memset( v , 0 , sizeof(v) ) ; 
	m = 0 ; // 素数数量 
	for ( int i = 2 ; i <= n ; i ++ )
	{
		if ( v[i] == 0 ) {
			v[i] = i ; 
			prime[++m] = i ; 
		}	
		for ( int j = 1 ; j <= m ; j ++ )
		{
			if ( prime[j] > v[i] || prime[j] > n / i ) break ; 
			v[i*prime[j]] = prime[j] ; 
		}
	} 
} */ 
}
void divide(){/* 质因数分解 
void divide(int n)
{
	m = 0 ; 
	for ( int i = 2 ; i <= sqrt(n) ; i ++ )
	{
		if ( n % i == 0 ) 
		{
			p[++m] = i , c[m] = 0 ; 
			while ( n % i == 0 ) n /= i , c[m]++ ; 
		}
	}
	if ( n > 1 ) p[++m] = n , c[m] = 1 ; 
} */ 
}
void build(){/* 线段树建树 
void build( int p , int l , int r )
{
	t[p].l = l , t[p].r = r ; 
	if ( l == r ) { t[p].dat = a[l] ; return ; } 
	int mid = ( l + r ) / 2 ; 
	build( p * 2 , l , mid ) ; 
	build( p * 2 + 1 , mid + 1 , r ) ; 
	t[p].dat = max( t[p*2].dat , t[p*2+1].dat ) ; 	
} */ 
}
void change(){/* 线段树单点修改
void change( int p , int x , int v )
{
	if ( t[p].l == t[p].r ) { t[p].dat = v ; return ; } 
	int mid = ( t[p].l + t[p].r ) / 2 ; 
	if ( x <= mid ) change( p * 2 , x , v ) ; 
	else change( p * 2 + 1 , x , v ) ; 
	t[p].dat = max( t[p*2].dat , t[p*2+1].dat )	;
} */
}
void ask(){/* 线段树区间查询 
int ask( int p , int l , int r )
{
	if ( l <= t[p].l && r >= t[p].r ) return t[p].dat ; 
	int mid = ( t[p].l + t[p].r ) / 2 ; 
	int val = -(1<<30) ; 
	if ( l <= mid ) val = max( val , ask( p * 2 , l , r ) ) ; 
	if ( r > mid ) val = max( val , ask( p * 2 + 1 , l , r ) ) ; 
	return val ; 
} */
}
void tarjan(){/*  tarjan找割边 
void tarjan( int x , int in_edge )
{
	dfs[x] = low[x] = ++num ; 
	for ( int i = head[x] ; i ; i = nxt[i] )
	{
		int y = ver[i] ; 
		if ( !dfn[y] )
		{
			tarjan( y , i ) ; 
			low[x] = min( low[x] , low[y] ) ; 
			if ( low[y] > dfn[x] ) 
				bridge[i] = bridge[i^1] = true ; 	
		} 
		else if ( i != ( in_edge ^ 1 ) )
			low[x] = min( low[x] , dfn[y] ) ; 
	}
} */
}
void lisanhua(){/* 离散化 
//input:
//5
//9 1 0 5 4
int n = 0;
struct node
{
	int x, id;
}a[maxn];
int b[maxn] = {};

bool cmp(node &nd1, node &nd2)
{
	return nd1.x < nd2.x;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i].x);
		a[i].id = i;
	}
	sort(a+1, a+1+n, cmp);
	for(int i=1; i<=n; i++) b[a[i].id] = i;
	for(int i=1; i<=n; i++) printf("%d ", b[i]);
} */
} 
void bingchaji(){/*  并查集
//查找祖先节点
int getfa(int x)
{
	if(x == fa[x]) return fa[x];
	return fa[x] = getfa(fa[x]);
}

//将y合并到x
void merge(int x, int y)
{
	int fx = getfa(x);
	int fy = getfa(y);
	if(fx != fy) fa[fy] = fx;
}

int main()
{ 
	int x = 0, y = 0;
	scanf("%d%d", &n, &m);
	//初始化
	for(int i=1; i<=n; i++) fa[i] = i;
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	scanf("%d", &q);
	for(int i=1; i<=q; i++)
	{
		scanf("%d%d", &x, &y);
		int fx = getfa(x);
		int fy = getfa(y);
		if(fx == fy) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
} 

2 : 维护到祖宗节点距离的并查集
const int maxn = 200010;
int n = 0;
//fa[]存储每个点的祖宗节点, d[]存储x到fa[x]的距离
int fa[maxn] = {}, d[maxn] = {};

//返回x的祖宗节点
int findset(int x)
{
	if(fa[x] != x) 
	{
		int y = findset(fa[x]);
		d[x] += d[fa[x]];
		fa[x] = y;
	}
	return fa[x];
}

//将y所在集合合并到x集合
void merge(int x, int y)
{
	int fx = findset(x), fy = findset(y);
	if(fx != fy)
	{
		fa[fy] = fx;
		d[fy] = d[x] + 1;
	}
}

// 初始化，假定节点编号是1~n
for(int i=1; i<=n; i++) fa[i] = i;
 */
} 
void shuzhuangshuzu(){/* 树状数组  
1 : 单点修改，区间查询 
const int maxn = 100010;
int n = 0, m = 0;
int c[maxn] = {};

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int val)
{
	while(x <= n)
	{
		c[x] += val;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int res = 0;
	while(x)
	{
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{ 
	char op[5];
	int a = 0, b = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a);
		add(i, a);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++)
	{
		scanf("%s%d%d", op, &a, &b);
		if(op[0] == 'S')	//区间查询
		{
			printf("%d\n", getsum(b) - getsum(a-1));
		}
		else	//单点修改
		{
			add(a, b);
		}
	}

    return 0; 
}	

2 : 区间修改，单点查询 
const int maxn = 100010;
int n = 0, m = 0;
int a[maxn] = {}, c[maxn] = {};

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int val)
{
	while(x <= n)
	{
		c[x] += val;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int res = 0;
	while(x)
	{
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{ 
	char op[5];
	int x = 0, y = 0, z = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]); 
	}
	scanf("%d", &m);
	for(int i=1; i<=m; i++)
	{
		scanf("%s", op);
		if(op[0] == 'Q')	//单点查询
		{
			scanf("%d", &x);
			printf("%d\n", getsum(x) + a[x]);
		}
		else	//区间修改
		{
			scanf("%d%d%d", &x, &y, &z);
			add(x, z);
			add(y+1, -z);
		}
	}

    return 0;
}
*/
}
void shupao(){/* 树剖
#include<bits/stdc++.h>
typedef long long LL ;
#define int long long  
using namespace std;
const int N = 500010 ; 
#define lc u<<1 
#define rc u<<1|1 
int n , m , a , b , root , p ; 
int w[N] ; 
vector<int> e[N] ; 
int fa[N] , dep[N] , sz[N] , son[N] ; 
int top[N] , id[N] , nw[N] , cnt ; // id[u] 存u刨分后的新编号 ， nw[cnt] 存新编号在树中对应节点的权值 
void dfs1( int u , int father )
{
	fa[u] = father ; 
	dep[u] = dep[father] + 1 ; 
	sz[u] = 1 ; 
	for ( int v : e[u] )
	{
		if ( v == father ) continue ; 
		dfs1( v , u ) ; 
		sz[u] += sz[v] ; 
		if ( sz[v] > sz[son[u]] )
			son[u] = v ; 		
	}	
} 

void dfs2( int u , int t )
{
	top[u] = t ; 
	id[u] = ++ cnt ; 
	nw[cnt] = w[u] ; 
	if ( !son[u] ) return ; 
	dfs2( son[u] , t ) ; 
	for ( int v : e[u] ) 
	{
		if ( v != son[u] && v != fa[u] )
			dfs2( v , v ) ; 
	}
}

struct tree{
	int l , r ; 
	int add , sum ; 
}tr[N*4];


void pushup( int u )
{
	tr[u].sum = tr[lc].sum + tr[rc].sum ; 
}

void pushdown( int u )
{
	if ( tr[u].add )
	{
		tr[lc].sum += tr[u].add * ( tr[lc].r - tr[lc].l + 1 ) ; 
		tr[rc].sum += tr[u].add * ( tr[rc].r - tr[rc].l + 1 ) ; 
		tr[lc].add += tr[u].add ; 
		tr[rc].add += tr[u].add ; 
		tr[u].add = 0 ; 
	}
}

void build( int u , int l , int r )
{
	tr[u] = { l , r , 0 , nw[l] } ; 
	if ( l == r ) return  ; 
	int mid = ( l + r ) >> 1 ; 
	build( lc , l , mid ) ; 
	build( rc , mid + 1 , r ) ; 
	pushup(u) ; 
}

void update( int u , int l , int r , int k )
{
	if ( l <= tr[u].l && r >= tr[u].r )
	{
		tr[u].add += k ; 
		tr[u].sum += k * ( tr[u].r - tr[u].l + 1 ) ; 
		return ;
	}
	pushdown(u) ; 
	int mid = ( tr[u].l + tr[u].r ) >> 1 ; 
	if ( l <= mid ) update( lc , l , r , k ) ; 
	if ( r > mid ) update( rc , l , r , k ) ; 
	pushup(u) ; 
}

void update_path( int u , int v , int k )
{
	while( top[u] != top[v] )
	{
		if ( dep[top[u]] < dep[top[v]] ) swap( u , v ) ; 
		update( 1 , id[top[u]] , id[u] , k ) ; 
		u = fa[top[u]] ; 
	}
	if ( dep[u] < dep[v] ) swap( u , v ) ; 
	update( 1 , id[v] , id[u] , k ) ; 
}

void update_tree( int u , int k )
{
	update( 1 , id[u] , id[u] + sz[u] - 1 , k ) ; 
}

LL query( int u , int l , int r )
{
	if ( l <= tr[u].l && r >= tr[u].r ) return tr[u].sum ; 
	pushdown(u) ; 
	int mid = ( tr[u].l + tr[u].r ) >> 1 ; 
	LL res = 0 ; 
	if ( l <= mid ) res += query( lc , l , r ) ; 
	if ( r > mid ) res += query( rc , l , r ) ; 
	return res ; 
}


LL query_path( int u , int v )
{
	LL res = 0 ; 
	while ( top[u] != top[v] )
	{
		if ( dep[top[u]] < dep[top[v]] ) swap( u , v ) ; 
		res += query( 1 , id[top[u]] , id[u] ) ; 
		u = fa[top[u]] ; 
	}
	if ( dep[u] < dep[v] ) swap( u , v ) ; 
	res += query( 1 , id[v] , id[u] ) ; 
	return res ; 
}

LL query_tree( int u )
{
	return query( 1 , id[u] , id[u] + sz[u] - 1 ) ; 
}



signed main()
{
	scanf( "%lld%lld%lld%lld" , &n , &m , &root , &p ) ; 
	for ( int i = 1 ; i <= n ; i ++ ) scanf( "%lld" , &w[i] ) ; 
	for ( int i = 0 ; i < n - 1 ; i ++ )
	{
		scanf( "%lld%lld" , &a , &b ) ;
		e[a].push_back(b) ; 
		e[b].push_back(a) ; 
	}
	dfs1( root , 0 ) ; 
	dfs2( root , root ) ; 
	build( 1 , 1 , n ) ; 
	while ( m -- )
	{
		int t , u , v , k ; 
		scanf( "%lld%lld" , &t , &u ) ; 
		if ( t == 1 ) {
			scanf( "%lld%lld" , &v , &k ) ; 
			update_path( u , v , k ) ; 
		}
		else if ( t == 3 ) {
			scanf( "%lld" , &k ) ; 
			update_tree( u , k ) ;
		}
		else if ( t == 2 ){
			scanf( "%lld" , &v ) ; 
			printf( "%lld\n" , query_path( u , v ) % p ) ; 
		 } 
		else printf( "%lld\n" , query_tree(u) % p ) ; 
	}
	return 0;
}
*/
}
void kuasumi(){/* 快速幂 
#include <bits/stdc++.h>
#define int long long
const int  MOD =  1e9 + 7 ; 
using namespace std ; 
int n , k , sz   ; 
struct mat {
  	int a[110][110] ;    
  	mat (){memset(a,0,sizeof(a)) ;}
  	mat operator*(const mat& T) const {
    	mat res;
    	int r;
    	for (int i = 0; i < sz; ++i)
      		for (int k = 0; k < sz; ++k) {
        		r = a[i][k];
        		for (int j = 0; j < sz; ++j)
          			res.a[i][j] += T.a[k][j] * r, res.a[i][j] %= MOD;
      		}
    	return res;
  	}
    mat operator^(int x) const {
    mat res, bas;
    for (int i = 0; i < sz; ++i) res.a[i][i] = 1;
    for (int i = 0; i < sz; ++i)
      	for (int j = 0; j < sz; ++j) bas.a[i][j] = a[i][j] % MOD;
    while (x) {
      if (x & 1) res = res * bas;
      bas = bas * bas;
      x >>= 1;
    }
    return res;
  }
}b,c; 
signed main ()
{
    cin>>n>>k;
    sz = n ; 
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++ )
        {
            cin >> b.a[i][j] ; 
        }
    }
    c = b^k ; 
for ( int i = 0 ; i < n ; i ++ )
{
    for ( int j = 0 ; j < n ; j ++ )
    {
        cout << c.a[i][j] << ' ' ;  
    }
    cout << endl ; 
}
*/
}





int main ()
{
	cout << "Hello,World!" ;
	return 0 ; 
}

