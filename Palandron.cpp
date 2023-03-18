// Longest Palandrom using Gap stritagy. 

string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        bool dp[n][n];
        
        int idx=-1,idy=-1;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=i+gap;j<n;j++,i++)
            {
               if(gap==0)
                   dp[i][j]=true;
                else if(gap==1)
                {
                  
                    if(s[i]==s[j])dp[i][j]=true;
                    else dp[i][j]=false;
                }
                else if(gap>1)
                {
                    if(s[i]==s[j] and dp[i+1][j-1]==true)
                        dp[i][j]=true;
                    else dp[i][j]=false;
                }
                if(dp[i][j]==true)
                  {
                     idx=i;
                    idy=j;
                 }
            }
            
        }
        int total=idy-idx+1;
        return s.substr(idx,total);
    }
