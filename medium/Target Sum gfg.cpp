class Solution {
  public:
    int n;
    int helper(int in,int tar,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=n)return tar==0;
        if(dp[in][tar+2000]!=-1)return dp[in][tar+2000];
        int op1=helper(in+1,tar-a[in],a,dp);
        int op2=helper(in+1,tar+a[in],a,dp);
        return dp[in][tar+2000]=op1+op2;
    }
  
  
    int totalWays(vector<int>& arr, int target) 
    {
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(5000,-1));
        return helper(0,target,arr,dp);
    }
};
