class Solution {
  public:
    int countSquare(vector<vector<int>>& a, int x)
    {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)for(int j=1;j<m;j++)a[i][j]+=a[i][j-1];
            
        int ans=0;
        for(int l=0;l<m;l++)
        {
            for(int r=l;r<m;r++)
            {
                int cs=r-l+1;
                int psum=0;
                for(int j=0;j<n;j++)
                {
                    psum+=a[j][r];
                    if(l-1>=0)psum-=a[j][l-1];
                    if(j>=cs)
                    {
                        psum-=a[j-cs][r];
                        if(l-1>=0)psum+=a[j-cs][l-1];
                    }
                    if(j>=cs-1 && psum==x)ans++;
                }
            }
        }
        return ans;
    }
};
