// SOLVE 2D I ONE D

int solveInOneD(vector<int>&arr)
    {
        int n=arr.size();
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)curr++;
            else curr=0;
            ans=max(ans,curr);
        }
        // cout<<ans<<endl;
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size(),m=matrix[0].size();
        int area=0;
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,1);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    temp[k]=(temp[k]&matrix[j][k]);
                }
                int currB=solveInOneD(temp);
                int currL=(j-i+1);
                int a=currL*currB;
                // if(i==)
                area=max(area,a);
            }
        }
        
        return area;
    }


// ...............................
