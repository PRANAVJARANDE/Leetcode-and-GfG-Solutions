class Solution {
public:

    int sz;
    int helper(int in,int mask,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(in>=sz/2)return 0;
        if(mask==0)return 0;
        if(dp[in][mask]!=-1)return dp[in][mask];
        int ans=0;
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                if((mask & (1<<j)) && (mask & (1<<i)))
                {
                    int nmask=mask ^ (1<<i) ^ (1<<j);
                    int res=(in+1)*__gcd(nums[i],nums[j])+helper(in+1,nmask,nums,dp);
                    ans=max(ans,res);
                }
            }
        }
        return dp[in][mask]=ans;
    }

    int maxScore(vector<int>& nums) 
    {
        sz=nums.size();
        vector<vector<int>>dp((sz/2)+1,vector<int>(1<<sz,-1));
        int ans=helper(0,(1<<sz)-1,nums,dp);
        return ans;
    }
};
