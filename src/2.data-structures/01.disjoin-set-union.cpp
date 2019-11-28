struct DSU 
{
    vector<int> p;
    vector<int> sz;

    DSU(int n) 
	{
        FOR(i, 0, n) 
		{
            p.push_back(i);
            sz.push_back(1);
        }
    }

    int find(int a) 
	{
        return p[a] = p[a] == a ? a : find(p[a]);
    }

    bool same(int a, int b) 
	{
        return find(a) == find(b);
    }

    void unite(int a, int b) 
	{
        a = find(a);
        b = find(b);
        if(sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
    }
};