#include<cstdio>
#include<queue>
#include<iostream>
#include <utility>
#include <algorithm>  
#include<vector>
using namespace std;


const int MAX_V = 100000+10;
const int INF = 0x3f3f3f3f;

struct edge
{
	int to, cost;
	edge(int x, int y) :to(x), cost(y) {}
};
typedef pair<int, int> P;//first是最短距离，second是顶点编号。

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
		//p.first是每次结算后的最小结点的最小距离，这个数据在进入p之后不再更新。
	    //d[v]是该节点的结算到现在的最小距离，这个是在每一次循环之后都会更新的（如果需要更新）
		if (d[v] < p.first) continue;
		for (int i = 0; i < int(G[v].size()); i++)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}



int main()
{
	int  n;
	cin >> V >> n;

	int q,w,e;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &q, &w, &e);
		G[q-1].push_back(edge(w-1,e));
		G[w-1].push_back(edge(q-1, e));
	}
	dijkstra(0);
	if (d[V - 1] == INF)
		cout << -1 << endl;
	else
		cout << d[V - 1] << endl;
	return 0;
}