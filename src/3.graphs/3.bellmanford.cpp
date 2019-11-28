struct Edge
{
	Edge(int64 t = 0, int64 c = 0) : t(t), c(c) {}
	int64 t, c;
};
int64 INF = 1e17+17;
struct Node
{
	int64 d;
	vector<Edge> e;
};
 
vector<Node> g;
void Refresh()
{
	for (auto& v : g) v.d = INF;
}

void FB(int64 s,bool again = false)
{
	if (!again)
	{
		Refresh();
		g[s].d = 0;
	}
 
	for (int64 step = 0; step < g.size() - 1; ++step)
	{
		for (int64 i = 0; i < g.size(); ++i)
		{
			if (g[i].d == INF) continue;
			for (const auto& e : g[i].e)
			{
				int64 u = e.t;
				int64 c = e.c;
 
				if (g[u].d > g[i].d + c)
				{
					if (!again) g[u].d = min(INF, g[i].d + c);
					else g[u].d = -INF; // negative cycle
				}
			}
		}
	}	
}

FB(s);
FB(s, true);