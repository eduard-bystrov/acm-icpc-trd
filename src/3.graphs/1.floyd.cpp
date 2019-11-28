vector<vector<int64>> g(n, vector<int64>(n));
for (int i = 0; i < n; ++i)
{
	for (int j = 0; j < n; ++j)
	{
		cin >> g[i][j];
	}
}

for (int k = 0; k < n; ++k)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		}
	}
}