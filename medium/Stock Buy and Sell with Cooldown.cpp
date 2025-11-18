class Solution {
  public:
    
    int helper(int in,int buy,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=a.size())return 0;
        
        if(dp[in][buy]!=-1)return dp[in][buy];
        
        // do nothing 
        int op1=helper(in+1,buy,a,dp);
        
        //buy or sell
        int op2=0;
        int nin=in+1;
        if(buy)op2-=a[in];
        else
        {
            op2+=a[in];
            nin++;
        }
        op2+=helper(nin,!buy,a,dp);
        return dp[in][buy]=max(op1,op2);
    }
  
  
    int maxProfit(vector<int>& a) 
    {
        vector<vector<int>>dp(a.size(),vector<int>(2,-1));
        return helper(0,1,a,dp);
    }
};
