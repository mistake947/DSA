//............................................... 
//There are n servers numbered from 0 to n - 1 connected by undirected
// server-to-server connections forming a network where connections[i] = [ai, bi]
// represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.
vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> id;
    vector<int> lowlink;
    vector<bool> vis;
    int time=0;
    void dfs(int node,int parent)
    {
        id[node]=lowlink[node]=time++;
        vis[node]=true;
        for(int &x:graph[node])
        {
            if(parent==x)continue;
            if(vis[x]==false)
            {
                dfs(x,node);
                lowlink[node]=min(lowlink[node],lowlink[x]);
                if(id[node]<lowlink[x])
                    ans.push_back({node,x});
            }
            else 
                lowlink[node]=min(lowlink[node],id[x]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        lowlink.resize(n,0);
        id.resize(n,0);
        for(auto &x:connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
                dfs(i,i);
        }
        return ans;
    }


// ......................................................
