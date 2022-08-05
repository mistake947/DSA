 vector<int> dijkstra(int source,vector<vector<pair<int,int>>> &graph,int n)
    {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	vector<int> dist(n,INT_MAX);

	pq.push({0,source});
	dist[source]=0;

	while(!pq.empty())
	{
		auto currPair=pq.top();
		pq.pop();

		int u=currPair.second;

		for(auto it: graph[u])
		{
            int v=it.first,wt=it.second;
        
			if(dist[u]+wt<dist[v])
			{
				dist[v]=dist[u]+wt;
				pq.push({dist[v],v});
			}
		}
	}

	return dist;
}