struct Node
{
	Node() : value(MIN_VALUE), push(MIN_VALUE) {}
	int64 value;
	int64 push;
};

struct ST
{
	ST(int n) : vec(4 * n),sz(4*n) {}
 
	void Set(int sl, int sr, int l, int r, int v, int64 value)
	{
		Refresh(v);
 
		if (sl == l && sr == r)
		{
			vec[v].value = max(vec[v].value, value);
			vec[v].push = value;
			return;
		}
 
		int mid = MID(sl, sr);
 
		if (r <= mid) Set(sl, mid, l, r, LSON(v), value);
		else if (l > mid) Set(mid + 1, sr, l, r, RSON(v), value);
		else
		{
			Set(sl, mid, l, mid, LSON(v), value);
			Set(mid + 1, sr, mid + 1, r, RSON(v), value);
		}
 
		Refresh(LSON(v));
		Refresh(RSON(v));
 
		vec[v].value = min(vec[LSON(v)].value, vec[RSON(v)].value);
	}
 
	void Refresh(int v)
	{
		if (v > sz) return;
 
		vec[v].value = max(vec[v].value, vec[v].push);
 
		if (RSON(v) >= sz || vec[v].push == MIN_VALUE) return;
 
		vec[LSON(v)].push = max(vec[v].push,vec[LSON(v)].push);
		vec[RSON(v)].push = max(vec[v].push, vec[RSON(v)].push);
		vec[v].push = MIN_VALUE;
	}
 
	int64 Get(int sl, int sr, int l, int r, int v)
	{
		Refresh(v);
		
		if (sl == l && sr == r)
		{
			return vec[v].value;
		}
 
		int mid = MID(sl, sr);
 
		if (r <= mid) return Get(sl, mid, l, r, LSON(v));
		else if (l > mid) return Get(mid + 1, sr, l, r, RSON(v));
		else
		{
			int64 left = Get(sl, mid, l, mid, LSON(v));
			int64 right = Get(mid + 1, sr, mid + 1, r, RSON(v));
 
			return min(left, right);
		}
	}
 
	vector<Node> vec;
	int sz;
};