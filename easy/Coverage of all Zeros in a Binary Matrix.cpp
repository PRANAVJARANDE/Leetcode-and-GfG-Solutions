class Solution {
  public:
    int findCoverage(vector<vector<int>>& a) 
    {
        int n=a.size(),m=a[0].size();
        int ans=0;
        vector<bool>vis(m,0);
        for(int i=0;i<n;i++)
        {
            bool pr=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    pr=1;
                    vis[j]=1;
                }
                else
                {
                    if(vis[j])ans++;
                    if(pr)ans++;
                }
            }
        }
        
        vis=vector<bool>(m,0);
        for(int i=n-1;i>=0;i--)
        {
            bool pr=0;
            for(int j=m-1;j>=0;j--)
            {
                if(a[i][j]==1)
                {
                    pr=1;
                    vis[j]=1;
                }
                else
                {
                    if(vis[j])ans++;
                    if(pr)ans++;
                }
            }
        }
        return ans;
    }
};
