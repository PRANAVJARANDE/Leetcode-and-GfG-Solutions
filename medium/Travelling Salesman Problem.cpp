class Solution {
  public:
    
    int n;
    int helper(int in,int mask,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(dp[in][mask]!=-1)return dp[in][mask];
        int ans=INT_MAX;
        bool flag=0;
        for(int i=1;i<n;i++)
        {
            if(!(mask & (1<<i)))
            {
                flag=1;
                int res=a[in][i]+helper(i,mask | (1<<i),a,dp);
                ans=min(ans,res);
            }
        }
        if(flag==0)return dp[in][mask]=a[in][0];
        return dp[in][mask]=ans;
    }
  
    int tsp(vector<vector<int>>& a) 
    {
        n=a.size();
        int mask=0;
        vector<vector<int>>dp(n,vector<int>(1<<n,-1));
        int ans=helper(0,mask,a,dp);
        return ans;
    }
};
