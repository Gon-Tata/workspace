#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int ans[1005][1005], dist[1005][1005]; 
const int inf = 0x3f3f3f3f;

struct node {
	int val, dis;
} c[1005];

bool cmp (node x, node y) {
	return x.val < y.val;
}

int main () {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i].val);
		c[i].dis = i;
	}
	sort(c + 1, c + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				dist[c[i].dis][c[j].dis] = min(dist[c[i].dis][c[j].dis], dist[c[i].dis][c[k].dis] + dist[c[k].dis][c[j].dis]);
				ans[c[i].dis][c[j].dis] = min(ans[c[i].dis][c[j].dis], dist[c[i].dis][c[j].dis] + max(c[i].val, max(c[j].val, c[k].val)));
			}
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", ans[a][b]);
	}
	return 0;
}