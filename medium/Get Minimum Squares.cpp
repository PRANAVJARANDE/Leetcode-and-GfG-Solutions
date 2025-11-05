class Solution {
  public:
  
    int helper(int n,vector<int>&dp)
    {
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans=1e6;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+helper(n-i*i,dp));
        }
        return dp[n]=ans;
    }
  
    int minSquares(int n) 
    {
        vector<int>dp(n+3,-1);
        int ans=helper(n,dp);
        return ans;
    }
};
