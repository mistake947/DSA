vector<int> dijkstra(int Source,vector<vector<int>> &graph)
{
    int n=graph.size();

    vector<int> dist(n,INT_MAX);


	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	

	pq.push({0,Source});

	dist[Source]=0;

	while(!pq.empty())
	{
		auto node=pq.top();

		pq.pop();

		int currNode=node.second;

		for(auto it: graph[currNode])
		{
			if(dist[currNode]+it.second<dist[it.first])
			{
				dist[it.first]=dist[currNode]+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
	}

	return dist;
}