
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
using namespace std;

const int mx = 10005;

struct edge
{
	double cost;
	int to;
	void read()
	{
		scanf("%d%lf", &to, &cost);
	}
} e;
 
vector<edge> G[mx];
double disTo[mx];
bool vis[mx];
int topo[mx], cnt;
 
void dfs(int i)
{
	vis[i] = true;
	for (int j = 0; j < G[i].size(); ++j)
		if (!vis[G[i][j].to]) dfs(G[i][j].to);
	topo[cnt++] = i;
}
 
/// 有向无环图上的最短路
void dagSP(int s)
{
	int i = cnt, j, v;
	while (topo[--i] != s); /// 先在topo中找到s
	memset(disTo, 100, sizeof(disTo));
	disTo[s] = 0.0;
	for (; i >= 0; --i)
	{
		v = topo[i];
		for (j = 0; j < G[v].size(); ++j)
		{
			e = G[v][j]; /// v视作e.from
			disTo[e.to] = min(disTo[e.to], disTo[v] + e.cost);
		}
	}
}
 
int main()
{
	int n, m, i, a;
	while (~scanf("%d%d", &n, &m))
	{
		for (i = 0; i < n; ++i) G[i].clear();
		while (m--)
		{
			scanf("%d", &a);
			e.read();
			G[a].push_back(e);
		}
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (i = 0; i < n; ++i)
			if (!vis[i]) dfs(i);
		dagSP(5);
		for (i = 0; i < n; ++i)
			printf("5 to %d : %.2f\n", i, disTo[i]);
		putchar(10);
	}
	return 0;
}