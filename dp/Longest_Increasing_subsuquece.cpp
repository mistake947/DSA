 //-----    Print and lenght of LONGEST INCREASING SUBSEQUENCE 
    vector<int> pathOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub, subIndex; // Store index instead of value for tracing path purpose
        vector<int> trace(n, -1); // trace[i] point to the index of previous number in LIS
        for (int i = 0; i < n; ++i) {
            if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
                if (!sub.empty()) 
                    trace[i] = subIndex[sub.size() - 1];
                sub.push_back(nums[i]);
                subIndex.push_back(i);
            } else {
                int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                if (idx > 0)
                    trace[i] = subIndex[idx - 1];
                sub[idx] = nums[i];
                subIndex[idx] = i;
            }
        }
        vector<int> path;
        int t = subIndex[subIndex.size() - 1];
        while (t != -1) {
            path.push_back(nums[t]);
            t = trace[t];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    vector<int> nums = {2, 6, 8, 3, 4, 5, 1};
    vector<int> res = Solution().pathOfLIS(nums); // [2, 3, 4, 5]
    for (int x : res) cout << x << " "; 
    return 0;
}


// ........................................................

// NUMBER OF LONGEST INCREASING SUBSQUENCE   N*N

int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0, maxxl=1;
        vector<int>dp(n,1);
        vector<int>count(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]) 
                {
                    if(dp[i]<dp[j]+1)
                    {
                         dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if(dp[i]==dp[j]+1)count[i]+=count[j];
                   
                    
                }
                maxxl=max(maxxl,dp[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxxl)ans+=count[i];
        }
      return ans;
        
    }


// .......................................................................................
