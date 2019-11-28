struct Node
{
	int in, lowLink;
	vector<int> e;
	bool ans = false;
};

int TIME = 0;
void DFS_T(int v, int p)
{
	g[v].in = g[v].lowLink = ++TIME;
 
	int children = 0;
 
	for (int i = 0; i < g[v].e.size(); ++i)
	{
		int to = g[v].e[i];
 
		if (to == p) continue;
 
		if (g[to].in == 0)
		{
			DFS_T(to, v);
			children++;
			g[v].lowLink = min(g[v].lowLink, g[to].lowLink);
 
 
			if (g[v].in <= g[to].lowLink && p != -1)
			{
				g[v].ans = true;
			}
		}
		else
		{
			g[v].lowLink = min(g[v].lowLink, g[to].in);
		}
	}
	
	if (children > 1 && p == -1) g[v].ans = true;
}