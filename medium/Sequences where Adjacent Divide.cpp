class Solution {
  public:
    
    int n,m;
    int dp[12][12];
    int helper(int in,int pv)
    {
        if(in>=n)return 1;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            if(in==0)
            {
                ans+=helper(in+1,i);
                continue;
            }
            if(i%pv==0)ans+=helper(in+1,i);
            else if(pv%i==0)ans+=helper(in+1,i);
        }
        return dp[in][pv]=ans;
    }
  
    int count(int n, int m) 
    {
        if(n==1)return m;
        this->n=n;
        this->m=m;
        memset(dp,-1,sizeof(dp));
        return helper(0,1);
    }
};
