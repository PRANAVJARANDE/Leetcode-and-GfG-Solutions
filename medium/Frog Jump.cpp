class Solution {
  public:
    
    long long n;
    long long helper(int in,vector<int>&a,vector<long long>&dp)
    {
        if(in>=n-1)return 0;
        if(dp[in]!=-1)return dp[in];
        long long op1=abs(a[in]-a[in+1])+helper(in+1,a,dp);
        long long op2=INT_MAX;
        if(in+2<n)op2=abs(a[in]-a[in+2])+helper(in+2,a,dp);
        return dp[in]=min(op2,op1);
    }
  
    int minCost(vector<int>& a) 
    {
        n=a.size();
        vector<long long>dp(n,-1);
        long long ans=helper(0,a,dp);
        return ans;
    }
};
