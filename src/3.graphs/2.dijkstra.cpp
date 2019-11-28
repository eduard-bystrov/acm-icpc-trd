struct Edge
{
	Edge(int64 a, int b) : cost(a), to(b) {};
	Edge() {};
 
	int64 cost;
	int to;
};
 
int64 INF = 1e11 + 77;
 
struct Node
{
	vector<Edge> edges;
	int64 dist = INF;
};
vector<Node> graph;
 
void Dij(int from)
{
	graph[from].dist = 0;
 
	priority_queue<pair<int64, int64>, vector<pair<int64, int64>>, greater<pair<int64, int64>>> que;
 
	que.push({ 0,from });
 
	while (!que.empty())
	{
		auto top = que.top(); que.pop();
		int v = top.second;
		int dis = top.first;
 
		if (graph[v].dist != dis) continue;
 
		for (auto& it : graph[v].edges)
		{
			int64 now = it.cost + dis;
 
			if (now < graph[it.to].dist)
			{
				graph[it.to].dist = now;
				que.push({ now,it.to });
			}
		}
	}
}