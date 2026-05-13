class Solution {
public:
    int minMoves(vector<int>& nums, int limit) 
    {
        int MX=300007;
        int n=nums.size();
        vector<int>dp(MX,0);

        for(int i=0;i<n/2;i++)
        {
            int mini=min(nums[i],nums[n-i-1]);
            int maxi=max(nums[i],nums[n-i-1]);
            dp[0]+=2;
            dp[mini+1]-=1;
            dp[maxi+limit+1]+=1;
            dp[maxi+mini]-=1;
            dp[maxi+mini+1]+=1;
        }

        int ans=INT_MAX;
        for(int i=1;i<MX;i++)
        {
            dp[i]+=dp[i-1];
            ans=min(ans,dp[i]);
        }
        
        return ans;
    }
};
