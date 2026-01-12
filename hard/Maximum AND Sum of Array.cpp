class Solution {
public:

    int sz,n;
    int helper(int in,int mask,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][mask]!=-1)return dp[in][mask];
        int ans=0;
        int div=1;
        for(int j=1;j<=sz;j++)
        {
            if((mask/div)%3)
            {
                int res=(nums[in] & j)+helper(in+1,mask-div,nums,dp);
                ans=max(ans,res);
            }
            div*=3;
        }
        return dp[in][mask]=ans;
    }

    int maximumANDSum(vector<int>& nums, int numSlots) 
    {
        n=nums.size();
        sz=numSlots;
        int maxi=powl(3,sz);
        vector<vector<int>>dp(n,vector<int>(maxi,-1));
        return helper(0,maxi-1,nums,dp);
    }
};
