class Solution {
  public:
    
    int n,m;
    int helper(int in,int c1,int c2,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][c1][c2]!=-1)return dp[in][c1][c2];
        int ans=0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nr=in+1;
                int nc1=c1+i;
                int nc2=c2+j;
                int cnt=0;
                if(!(0<=nc1 && nc1<m))continue;
                if(!(0<=nc2 && nc2<m))continue;
                if(nr<n)
                {
                    cnt+=a[nr][nc1];
                    cnt+=a[nr][nc2];
                    if(nc1==nc2)cnt-=a[nr][nc1];
                }
                cnt+=helper(nr,nc1,nc2,a,dp);
                ans=max(ans,cnt);
            }
        }
        if(in==0)ans+=a[0][0]+a[0][m-1];
        return dp[in][c1][c2]=ans;
    }
  
    int maxChocolate(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,a,dp);
    }
};
