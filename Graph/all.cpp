#include <bits/stdc++.h>

using namespace std;
#define ll long long

// this is union  and find class;

class UnionFind {
  int num;
  int numComponents;
  vector<int> rank;
  vector<int> parent;

public:
  UnionFind(int n) {
    num = n;
    numComponents = n;
    rank = vector<int>(n, 0);
    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int size() { return num; }

  int components() { return numComponents; }

  int find(int p) {
    while (p != parent[p]) {
      parent[p] = parent[parent[p]];
      p = parent[p];
    }
    return p;
  }

  void unionn(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq)
      return;
    if (rank[rootp] < rank[rootq])
      parent[rootp] = rootq;
    else {
      parent[rootq] = rootp;
      if (rank[rootp] == rank[rootq]) {
        rank[rootp]++;
      }
    }
    numComponents--;
  }

  int connected(int p, int q) { return find(p) == find(q); }
};
//..............................................................
        using  DFS
// detetect cycle using color 0 1 2
// 0 means unvishted
//1 mwans visited but under process it means child are not visited
//2 means complete visted

 stack<int>st;
    bool dfs(int curr,vector<int>&vis,vector<vector<int>>&graph)
    {
        if(vis[curr]==1)return false;
        else if(vis[curr]==0)
        {
            vis[curr]=1;
        for(auto c:graph[curr])
        {
            if(vis[c]==0)
            {
              bool cheak= dfs(c,vis,graph);
                if(cheak==false) return false;
            }
            if(vis[c]==1) return false;// ye line imoratnt hai
        }
        }
        st.push(curr);
        vis[curr]=2;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n);
        
        vector<int>my_ans;
         vector<int>vis(n,0);
        
        for(auto p:pre)
        {
            graph[p[1]].push_back(p[0]);
           
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
             bool ccc=true;
            ccc=dfs(i,vis,graph);
            if(ccc==false) return {};
            }
        }
       
        while(!st.empty())
        {
          my_ans.push_back(st.top());
            st.pop();
        }
        return my_ans;
    }
};

//---------------------------------------------------------------------------------------
                 using BFS 

bool cycle(int n, vector<vector<int>>& pre) {
     
        vector<vector<int>>graph(n);
        queue<int>q;
        vector<bool>vis(n,false);
        vector<int>indegree(n,0);
        for(auto p:pre)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]+=1;
        }
        int count=0;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            vis[t]=true;
             count++;
            for(auto child:graph[t])
            {
               // if(!vis[child])  opttional
                {
                    
                    indegree[child]--;
                   
                    if(indegree[child]==0)q.push(child);
                }
            }
        }
        if(count==n)return true;
        return false;
    }
};
//........................................................................
