void bfs(int node, vector<int>&dis,vector<vector<int>>&g)
    {
        int n=dis.size();
        queue<int>q;
        vector<int>vis(n,0);
        q.push(node);
        dis[node]=0;
      // yaha visti nahi karte bina .
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            if(vis[curr]==1)continue;
             vis[curr]=1;
            for(auto v:g[curr])
            {
              
               
                if(vis[v]==0)
                {
                     dis[v]=min(dis[v],dis[curr]+1);
                   
                    q.push(v);
                    
                    //yaha vistit nahi karte 
                }
            }
        }
    }
