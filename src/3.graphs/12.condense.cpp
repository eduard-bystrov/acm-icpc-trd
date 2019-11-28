struct Node
{
	int in = 0;
	int lowLink = 0;
	int color = 0;
	int inStack = false;
	vector<int> e;
};
 
int TIME = 0;
int COLOR = 0;
vector<int> st;

void DFS_T(int f, int p)
{
	st.push_back(f);
	g[f].in = g[f].lowLink = ++TIME;
	g[f].inStack = true;
	 
	for (auto& it : g[f].e)
	{
		//if (it == p) continue;
		if (g[it].in == 0)
		{
			DFS_T(it, f);
			g[f].lowLink = min(g[f].lowLink, g[it].lowLink);
 
			// bridges
			// cut-points
		}
		else if (g[it].inStack)
		{
			g[f].lowLink = min(g[f].lowLink, g[it].in);
		}
	}
 
	if (g[f].lowLink == g[f].in)
	{
		COLOR++;
		int x;
		do
		{
			x = st.back(); st.pop_back();
			g[x].color = COLOR;
			g[x].inStack = false;
		} while (x != f);
	}
}