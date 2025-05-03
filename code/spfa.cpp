#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int maxm = maxn * maxn;
const int inf = 0x7f7f7f7f;

int n = 0, m = 0;
int h[maxn] = {}, to[maxm] = {}, nxt[maxm] = {}, w[maxm] = {}, tot = 0;
int dis[maxn] = {}; 
bool vis[maxn] = {}; 
queue<int> q;

void addedge(int x, int y, int z)
{
	to[++tot] = y;
	nxt[tot] = h[x];
	w[tot] = z;
	h[x] = tot;
}

void spfa(int x)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[x] = 0;
	q.push(x);
	 
	while(q.size())
	{ 
		x = q.front();
		q.pop();
		vis[x] = false;
		
		for(int i=h[x]; i; i=nxt[i])
		{
			int y = to[i];
			if(dis[y] > dis[x] + w[i])
			{
				dis[y] = dis[x] + w[i];
				if(!vis[y]) q.push(y);
			}
		}
	}
}
 
int main()
{	
	int x = 0, y = 0, z = 0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
		addedge(y, x, z);
	}
	
	spfa(1);
	
	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		if(dis[i] == 0x3f3f3f3f) 
		{
			printf("-1");
			return 0;
		}
		if(ans < dis[i]) ans = dis[i];
	}
	printf("%d", ans);
	return 0;
}
