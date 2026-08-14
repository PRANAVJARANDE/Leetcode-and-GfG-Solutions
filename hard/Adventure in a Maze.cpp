class Solution {
  public:
  
    const int MOD=1e9+7;
    vector<int> findWays(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,INT_MIN));
        dis[0][0]=a[0][0];
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0 && a[i-1][j]!=1 && dp[i-1][j]!=0)
                {
                    dp[i][j]=(dp[i][j]%MOD+dp[i-1][j]%MOD)%MOD;
                    dis[i][j]=max(dis[i][j],dis[i-1][j]+a[i][j]);
                }
                if(j-1>=0 && a[i][j-1]!=2 && dp[i][j-1]!=0)
                {
                    dp[i][j]=(dp[i][j]%MOD+dp[i][j-1]%MOD)%MOD;
                    dis[i][j]=max(dis[i][j],dis[i][j-1]+a[i][j]);
                }
            }
        }
        int paths=dp[n-1][m-1];
        int maxi=dis[n-1][m-1];
        if(paths==0)maxi=0;
        return {paths,maxi};
    }
};
