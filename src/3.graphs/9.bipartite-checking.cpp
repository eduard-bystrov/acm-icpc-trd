vector<char> part (n, -1);
bool ok = true;
vector<int> q (n);
for (int st=0; st<n; ++st)
	if (part[st] == -1) {
		int h=0, t=0;
		q[t++] = st;
		part[st] = 0;
		while (h<t) {
			int v = q[h++];
			for (size_t i=0; i<g[v].size(); ++i) {
				int to = g[v][i];
				if (part[to] == -1)
					part[to] = !part[v],  q[t++] = to;
				else
					ok &= part[to] != part[v];
			}
		}
	}

puts (ok ? "YES" : "NO");