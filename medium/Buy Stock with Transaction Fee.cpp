class Solution {
  public:
    
    int n;
    int helper(int in,int tk,vector<int>&a,int k,vector<vector<int>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][tk]!=-1)return dp[in][tk];
        int op1=helper(in+1,tk,a,k,dp);
        int op2;
        if(tk==0)op2=-a[in]-k+helper(in+1,1,a,k,dp);
        else op2=a[in]+helper(in+1,0,a,k,dp);
        return dp[in][tk]=max(op1,op2);
    }
  
    int maxProfit(vector<int>& arr, int k) 
    {
        n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,0,arr,k,dp);
    }
};
