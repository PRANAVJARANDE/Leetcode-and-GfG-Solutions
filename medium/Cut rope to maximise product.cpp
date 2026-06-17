class Solution {
public:

    int helper(int n, vector<int>& dp)
    {
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int res=max(i*(n - i),i*helper(n-i,dp));
            ans=max(ans,res);
        }
        return dp[n]=ans;
    }

    int maxProduct(int n)
    {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};
