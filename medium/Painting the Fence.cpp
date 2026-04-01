class Solution {
  public:
    
    int helper(int in,int flag,int n,int k,vector<vector<int>>&dp)
    {
        if(in>=n)return 1;
        if(dp[in][flag]!=-1)return dp[in][flag];
        
        int ans=0;
        
        // choose same as pv
        if(!flag && in!=0)
        {
            ans+=helper(in+1,1,n,k,dp);   
        }
        
        // diff from pv
        ans+=(k-1)*helper(in+1,0,n,k,dp);
        if(in==0)ans+=helper(in+1,0,n,k,dp);
        return dp[in][flag]=ans;
    }
  
    int countWays(int n, int k) 
    {
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,0,n,k,dp);
    }
};
