//--------------------------------------------------------------------  

int parent[21][60000];
    TreeAncestor(int n, vector<int>& par) {
        memset(parent,-1,sizeof(parent));
        for(int i=0;i<par.size();i++)
        {
            parent[0][i]=par[i];
        }
        for(int i=1;i<20;i++)
        {
            for(int node=0;node<par.size();node++)
            {
                int np=parent[i-1][node];
                if(np!=-1)
                 parent[i][node]=parent[i-1][np];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++)
        {
            if(k &(1<<i))
            {
                node=parent[i][node];
                if(node==-1)return -1;
            }
        }
        return node;
    }

//----------------------------------------------------------------------------------------------
