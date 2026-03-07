class Solution {
  public:
    
    int helper(int n,int m,int x,vector<vector<int>>&dp)
    {
        if(x<0)return 0;
        if(n==0)
        {
            if(x==0)return 1;
            return 0;
        }
        if(dp[n][x]!=-1)return dp[n][x];
        int ans=0;
        for(int i=1;i<=m;i++)ans+=helper(n-1,m,x-i,dp);
        return dp[n][x]=ans;
    }
    
    int noOfWays(int m, int n, int x) 
    {
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        int ans=helper(n,m,x,dp);
        return ans;
    }
};
