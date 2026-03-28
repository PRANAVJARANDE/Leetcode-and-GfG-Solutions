class Solution {
  public:
    
    int helper(int in,int sum,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=a.size())return (sum==0);
        if(dp[in][sum+301]!=-1)return dp[in][sum+301];
        int op1=helper(in+1,sum-a[in],a,dp);
        int op2=helper(in+1,sum+a[in],a,dp);
        return dp[in][sum+301]=op1+op2;
    }
  
    int countPartitions(vector<int>& arr, int diff) 
    {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(700,-1));
        return helper(0,diff,arr,dp);
    }
};
