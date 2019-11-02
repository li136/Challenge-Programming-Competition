//代码示例：
//从顶点from指向顶点to的权值为cost的边。

//就是时间复杂度太高
const int MAX_E=10000, MAX_V = 10000;
struct edge
{
	int from, to, cost;
};

edge es[MAX_E];//边

int d[MAX_V];//最短距离
int V, E;

void shortest_path(int s)
{
	memset(d, -1, sizeof(d));
	d[s] = 0;
	while (true)
	{
		bool update = false;
		for (int i = 0; i < E; i++)
		{
			edge e = es[i];
			if (d[e.from] != -1 && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update) break;
	}
}