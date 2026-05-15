class Solution {
public:
    
    int optimalKeys(int n) 
    {
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+1;
            for(int j=1;j<=i-3;j++)
            {
                dp[i]=max(dp[i],dp[j]*(i-j-1));
            }
        }
        return dp[n];
    }
};
