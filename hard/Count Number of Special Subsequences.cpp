class Solution {
public:

    // in --  indices of nums
    // pv -- previous value taken - 0 or 1 or 2

    int n;
    const int MOD=1e9+7;
    int helper(int in,int pv,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(in>=n)
        {
            if(pv==2)return 1;
            return 0;
        }
        if(dp[in][pv+1]!=-1)return dp[in][pv+1];
        //skip
        int op1=helper(in+1,pv,nums,dp)%MOD;
        //take
        int op2=0;
        if(nums[in]==pv || nums[in]==pv+1)op2=helper(in+1,nums[in],nums,dp)%MOD;
        return dp[in][pv+1]=((op1%MOD)+(op2%MOD))%MOD;
    }

    int countSpecialSubsequences(vector<int>& nums) 
    {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return helper(0,-1,nums,dp);
    }
};
