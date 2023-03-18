//--------------------------------------------------------------


// Given an integer array nums and an integer k,
// return true if it is possible to divide this array into
// k non-empty subsets whose sums are all equal.


class Solution {
public:
    int dp[1<<17][17];
    vector<int>sum;
    int target;
    
    int solve(int mask, int k)   // 111111 can take 1 , 0 means already taken
    {
        if(mask==0) return k==0;
         
        if(k==0)return 0;
        
        if(dp[mask][k]!=-1)return dp[mask][k];
         int ans=0;
        for(int submask=mask;submask;submask=(submask-1)&mask)   // travel in all submask of  111 0 111 // one valo pr
        {
            
            if(sum[submask]==target)
            {
               ans=solve(mask^submask,k-1);
                if(ans==true)
                {
                    return dp[mask][k]=ans;
                }
            }
        }
        
        return dp[mask][k]=ans;
        
    }
    
    bool canPartitionKSubsets(vector<int>& num, int k) {
        memset(dp,-1,sizeof(dp));
        int n=num.size();
       
        sum.resize(1<<n,0);
        for(int i=0;i<(1<<n);i++)
        {
            int curr=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))curr+=num[j];
            }
            sum[i]=curr;
        }
        int total=0;
        for(auto nu:num)total+=nu;
        if(total%k) return false;
        target=total/k;
        return solve((1<<n)-1,k);
    }
};



//-----------------------------------------------------------------------------------
