class Solution {
  public:
  
    int n;
    int helper(int in,int pv,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int pval=INT_MIN;
        if(pv!=n)pval=a[pv];
        
        int op1=helper(in+1,pv,a,dp);
        int op2=INT_MIN;
        if(pval<a[in])op2=a[in]+helper(in+1,in,a,dp);
        return dp[in][pv]=max(op1,op2);
    }
  
    int maxSumIS(vector<int>& a) {
        n=a.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,n,a,dp);
    }
};
