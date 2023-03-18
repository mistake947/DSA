  /// ye chek functon likhna hai
    bool cheak(vector<int>&piles,int h,int mid)
    {
        int sum=0;
        for(auto p:piles)
        {
            
            sum+= p%mid==0?p/mid: (p/mid)+1;
            if(sum>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxx=INT_MIN;
        for(auto p:piles)
        {
            maxx=max(maxx,p);
        }
        if(piles.size()==h) return maxx;
        else if(piles.size()==1 and h>=piles[0] ) return 1;
        int l=1, r=maxx;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(cheak(piles,h,mid)==true)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
        
    }
};

///
