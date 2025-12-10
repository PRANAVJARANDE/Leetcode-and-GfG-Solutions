class Solution {
  public:
    
    int helper(int l,int r,vector<vector<int>>&v1,vector<vector<int>>&dp)
    {
        int ans=INT_MAX;
        if(dp[l][r]!=-1)return dp[l][r];
        for(int mid=l;mid<=r;mid++)
        {
            int left=0;
            if(l<=mid-1)
            {
                left=v1[mid-1][1];
                if(l-1>=0)left-=v1[l-1][1];
                left+=helper(l,mid-1,v1,dp);
            }
            int right=0;
            if(mid+1<=r)
            {
                right=v1[r][1];
                if(mid>=0)right-=v1[mid][1];
                right+=helper(mid+1,r,v1,dp);
            }
            int curr=v1[mid][1];
            if(mid-1>=0)curr-=v1[mid-1][1];
            int res=left+right+curr;
            ans=min(ans,res);
        }
        return dp[l][r]=ans;
    }
    
    int minCost(vector<int> &keys, vector<int> &freq) 
    {
        int n=keys.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=keys[i];
            v1[i][1]=freq[i];
        }
        sort(v1.begin(),v1.end());
        for(int i=1;i<n;i++)v1[i][1]+=v1[i-1][1];
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=helper(0,n-1,v1,dp);
        return ans;
    }
};
