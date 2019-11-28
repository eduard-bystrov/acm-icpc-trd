struct Edge
{
	Edge(int a, int b, int c)
		: v(a),u(b),cost(c)
	{
	}

	int v;
	int u;
	int cost;

	bool operator<(const Edge& obj) const
	{
		return cost < obj.cost;
	}
};

vector<Edge> edges;

vector<int> p;
int dsu_get(int v)
{
	return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int v, int u)
{
	if (rand() & 1) swap(v, u);

	if (v != u) p[v] = u;
}

map<int, int> ids;
forn(i, m)
{
	int a, b, c;
	cin >> a >> b >> c;
	a--; b--;
	
	if (ids.find(a) == ids.end())
	{
		ids.insert(make_pair(a, ids.size()));
	}

	if (ids.find(b) == ids.end())
	{
		ids.insert(make_pair(b, ids.size()));
	}

	edges.push_back(Edge(a, b, c));
}

sort(all(edges));

forn(i, m)
{
	int v = ids.find(edges[i].v)->second;
	int u = ids.find(edges[i].u)->second;
	int cost = edges[i].cost;
	if (dsu_get(v) != dsu_get(u))
	{
		ans += cost;
		dsu_unite(dsu_get(v), dsu_get(u));
	}
}
