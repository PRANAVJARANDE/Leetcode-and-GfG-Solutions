class Solution {
  public:
    
    int helper(int in,int p1,int p2,int n,vector<vector<vector<int>>>&dp)
    {
        if(in>=n)
        {
            if(p1 || p2)return 0;
            return 1;
        }
        if(dp[in][p1][p2]!=-1)return dp[in][p1][p2];
        
        if(p1 && p2)return dp[in][p1][p2]=helper(in+1,0,0,n,dp);
        else if(p1)return dp[in][p1][p2]=helper(in+1,0,1,n,dp);
        else if(p2)return dp[in][p1][p2]=helper(in+1,1,0,n,dp);
        else
        {
            int op1=helper(in+1,0,0,n,dp);
            int op2=helper(in+1,1,1,n,dp);
            return dp[in][p1][p2]=op1+op2;
        }
    }
    
 
    int numberOfWays(int n) 
    {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(0,0,0,n,dp);
    }
};
