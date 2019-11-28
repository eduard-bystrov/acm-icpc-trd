struct Node
{
	int in, lowLink;
	vector<int> e;
};
 
vector<Node> g;

int TIME = 0;
void DFS_T(int v, int p)
{
	g[v].in = g[v].lowLink = ++TIME;
 
	for (int i = 0; i < g[v].e.size(); ++i)
	{
		int to = g[v].e[i];
 
		if (to == p) continue;
 
		if (g[to].in == 0)
		{
			DFS_T(to, v);
			g[v].lowLink = min(g[v].lowLink, g[to].lowLink);
 
			if (g[v].in < g[to].lowLink)
			{
				ans.insert(ids[{v, to}]);
			}
		}
		else
		{
			g[v].lowLink = min(g[v].lowLink, g[to].in);
		}
	}
}