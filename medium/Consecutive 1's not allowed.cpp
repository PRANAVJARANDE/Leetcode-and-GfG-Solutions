class Solution {
  public:
    
    int helper(int in,int pv,int n,vector<vector<int>>&dp)
    {
        if(in>=n)return 1;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int ans;
        if(pv==1)ans=helper(in+1,0,n,dp);
        else ans=helper(in+1,1,n,dp)+helper(in+1,0,n,dp);
        return dp[in][pv]=ans;
    }
  
    int countStrings(int n) 
    {
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return helper(0,2,n,dp);
    }
};
